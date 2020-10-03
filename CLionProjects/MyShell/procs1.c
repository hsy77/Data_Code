#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <curses.h>
//#include <timers.h>
#include <stdlib.h>
#include <limits.h>
#include <termcap.h>
#include <termios.h>
#include <time.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <assert.h>
#include <stdint.h>

typedef int endpoint_t;
typedef uint64_t u64_t;
typedef long unsigned int vir_bytes;

#define  USED        0x1
#define  IS_TASK    0x2
#define  IS_SYSTEM    0x4
#define  BLOCKED    0x8
#define TYPE_TASK    'T'
#define TYPE_SYSTEM    'S'
#define STATE_RUN    'R'

#define MAX_NR_TASKS 1023
#define SELF    ((endpoint_t) 0x8ace)
#define _MAX_MAGIC_PROC (SELF)
#define _ENDPOINT_GENERATION_SIZE (MAX_NR_TASKS+_MAX_MAGIC_PROC+1)
#define _ENDPOINT_P(e) \
((((e)+MAX_NR_TASKS) % _ENDPOINT_GENERATION_SIZE) - MAX_NR_TASKS)
#define  SLOT_NR(e) (_ENDPOINT_P(e) + 5)

#define CPUTIME(m, i) (m & (1L << (i)))
const char *cputimenames[] = { "user", "ipc", "kernelcall" };

#define CPUTIMENAMES (sizeof(cputimenames)/sizeof(cputimenames[0]))
unsigned int nr_procs, nr_tasks;

int nr_total=0;
int slot_a=0;
int pronum=0;
int filenum=0;

struct proc {
    int p_flags;
    endpoint_t p_endpoint;
    pid_t p_pid;
    u64_t p_cpucycles[CPUTIMENAMES];
    int p_priority;
    endpoint_t p_blocked;
    time_t p_user_time;
    vir_bytes p_memory;
    uid_t p_effuid;
    int p_nice;
    char p_name[16+1];
};

struct proc *proc = NULL, *prev_proc = NULL;
static inline u64_t make64(unsigned long lo, unsigned long hi)
{
    return ((u64_t)hi << 32) | (u64_t)lo;
}
void parse_file(pid_t pid)
{
    char path[PATH_MAX], name[256], type, state;
    int version, endpt, effuid;
    unsigned long cycles_hi, cycles_lo;
    FILE *fp;
    struct proc *p;
    int slot;
    int i;

    sprintf(path, "/proc/%d/psinfo", pid);
    //printf("555");
//    if(strcmp(path,"/proc/-1/psinfo")==0)
//        printf("get the pid=-1\n");
    
    if ((fp = fopen(path, "r")) == NULL)
        return;
    
    if (fscanf(fp, "%d", &version) != 1) {
        fclose(fp);
        return;
    }

    if (version != 0) {
        fputs("procfs version mismatch!\n", stderr);
        exit(1);
    }

    if (fscanf(fp, " %c %d", &type, &endpt) != 2) {
        fclose(fp);
        return;
    }
    filenum+=1;
   // printf("111");
    slot = SLOT_NR(endpt);
    slot=slot_a;
    slot_a+=2;
  
    //printf("%d,%d\n",endpt,slot);
    if(slot < 0 || slot >= nr_total) {
        fprintf(stderr, "top: unreasonable endpoint number %d\n", endpt);
        fclose(fp);
        return;
    }

    p = &proc[slot];

    if (type == TYPE_TASK)
        p->p_flags |= IS_TASK;
    else if (type == TYPE_SYSTEM)
        p->p_flags |= IS_SYSTEM;

    p->p_endpoint = endpt;
    p->p_pid = pid;

    if (fscanf(fp, " %255s %c %d %d %llu %*u %lu %lu",
        name, &state, &p->p_blocked, &p->p_priority,
        &p->p_user_time, &cycles_hi, &cycles_lo) != 7) {

        fclose(fp);
        return;
    }

    strncpy(p->p_name, name, sizeof(p->p_name)-1);
    p->p_name[sizeof(p->p_name)-1] = 0;

    if (state != STATE_RUN)
        p->p_flags |= BLOCKED;
    p->p_cpucycles[0] = make64(cycles_lo, cycles_hi);
    p->p_memory = 0L;

    if (!(p->p_flags & IS_TASK)) {
        int j;
        if ((j=fscanf(fp, " %lu %*u %*u %*c %*d %*u %u %*u %d %*c %*d %*u",
            &p->p_memory, &effuid, &p->p_nice)) != 3) {

            fclose(fp);
            return;
        }

        p->p_effuid = effuid;
    } else p->p_effuid = 0;

    for(i = 1; i < CPUTIMENAMES; i++) {
        if(fscanf(fp, " %lu %lu",
            &cycles_hi, &cycles_lo) == 2) {
            p->p_cpucycles[i] = make64(cycles_lo, cycles_hi);
        } else    {
            p->p_cpucycles[i] = 0;
        }
    }

    if ((p->p_flags & IS_TASK)) {
        if(fscanf(fp, " %lu", &p->p_memory) != 1) {
            p->p_memory = 0;
        }
    }

    p->p_flags |= USED;
    

    fclose(fp);
}
void parse_dir(void)
{
    DIR *p_dir;
    struct dirent *p_ent;
    pid_t pid;
    char *end;
    
    if ((p_dir = opendir("/proc/")) == NULL) {
        perror("opendir on " "/proc/");
        exit(1);
    }
    for (p_ent = readdir(p_dir); p_ent != NULL; p_ent = readdir(p_dir)) {
        pid = strtol(p_ent->d_name, &end, 10);
        //printf("%s",p_ent->d_name);
//        char buf[80];
//        getcwd(buf,sizeof(buf));
//        printf("current working directory: %s\n", buf);

        if (!end[0] && pid != 0)
        {
            //printf("%d\n",pid);
            pronum+=1;
            parse_file(pid);
             //printf("keyile");
        }


    }
//    p_ent=readdir(p_dir);
//    while(p_ent != NULL){
//        if(strncpy(p_ent->d_name,".",1)==0)
//            continue;
//        pid=strtol(p_ent->d_name,&end,10);
//        if(pid!=0 && !end[0]){
//            printf("%l\n",pid);
//            parse_file(pid);
//        }
//        p_ent=readdir(p_dir);
//    }

    closedir(p_dir);
}
struct tp {
    struct proc *p;
    u64_t ticks;
};
u64_t cputicks(struct proc *p1, struct proc *p2, int timemode)
{
    int i;
    u64_t t = 0;
    for(i = 0; i < CPUTIMENAMES; i++) {
        if(!CPUTIME(timemode, i))
            continue;
        if(p1->p_endpoint == p2->p_endpoint) {
            t = t + p2->p_cpucycles[i] - p1->p_cpucycles[i];
        } else {
            t = t + p2->p_cpucycles[i];
        }
    }

    return t;
}
void print_procs(
    struct proc *proc1, struct proc *proc2, int cputimemode)
{
    int p, nprocs;
    u64_t idleticks = 0;
    u64_t kernelticks = 0;
    u64_t systemticks = 0;
    u64_t userticks = 0;
    u64_t total_ticks = 0;
    int blockedseen = 0;
    static struct tp *tick_procs = NULL;
    //printf("444");
    if (tick_procs == NULL) {
        tick_procs = malloc(nr_total * sizeof(tick_procs[0]));

        if (tick_procs == NULL) {
            fprintf(stderr, "Out of memory!\n");
            exit(1);
        }
    }
//printf("555");
    for(p = nprocs = 0; p < nr_total; p++) {
        u64_t uticks;
        //printf("%d",proc2[p].p_flags);
        if(!(proc2[p].p_flags & USED))
            continue;
//        printf("ttt");
        tick_procs[nprocs].p = proc2 + p;
        tick_procs[nprocs].ticks = cputicks(&proc1[p], &proc2[p], cputimemode);
//        printf("ticks: %d",tick_procs[nprocs].ticks);
        uticks = cputicks(&proc1[p], &proc2[p], 1);
        total_ticks = total_ticks + uticks;
        if(p-5 == 317) {
            idleticks = uticks;
            continue;
        }
        if(p-5 == ((endpoint_t) -1)) {
            kernelticks = uticks;
        }
        if(!(proc2[p].p_flags & IS_TASK)) {
            if(proc2[p].p_flags & IS_SYSTEM)
                systemticks = systemticks + tick_procs[nprocs].ticks;
            else
                userticks = userticks + tick_procs[nprocs].ticks;
        }

        nprocs++;
    }
//printf("666");
    if (total_ticks == 0)
        return;
//    printf(" parsefile number:%d,pid numbers:%d\n",filenum,pronum);
//    printf("CPU states: %6.2f%% user, ", 100.0 * userticks / total_ticks);
//    printf("%6.2f%% system, ", 100.0 * systemticks / total_ticks);
//    printf("%6.2f%% kernel, ", 100.0 * kernelticks/ total_ticks);
//    printf("%6.2f%% idle", 100.0 * idleticks / total_ticks);
    printf("CPU states: %6.2f%% , ", 100.0 * (kernelticks+kernelticks+systemticks)/ total_ticks);
//    printf("888");
}
void get_procs(void)
{
   
    struct proc *p;
    int i;

    p = prev_proc;
    prev_proc = proc;
    proc = p;

    if (proc == NULL) {
        proc = malloc(nr_total * sizeof(proc[0]));

        if (proc == NULL) {
            fprintf(stderr, "Out of memory!\n");
            exit(1);
        }
    }

    for (i = 0; i < nr_total; i++)
        proc[i].p_flags = 0;
    
    parse_dir();
    
}
void getkinfo(void)
{
    FILE *fp;

    if ((fp = fopen("/proc/kinfo", "r")) == NULL) {
        
        exit(1);
    }

    if (fscanf(fp, "%u %u", &nr_procs, &nr_tasks) != 2) {
       
        exit(1);
    }

    fclose(fp);

    nr_total = (int) (nr_procs + nr_tasks);
}

int print_memory(void)
{
	FILE *fp;
	unsigned int pagesize;
	unsigned long total, free, largest, cached;

	if ((fp = fopen("/proc/meminfo", "r")) == NULL)
		return 0;

	if (fscanf(fp, "%u %lu %lu %lu %lu", &pagesize, &total, &free,
			&largest, &cached) != 5) {
		fclose(fp);
		return 0;
	}

	fclose(fp);

	printf("main memory: %ldK total, %ldK free, %ldK contig free, "
		"%ldK cached\n",
		(pagesize * total)/1024, (pagesize * free)/1024,
		(pagesize * largest)/1024, (pagesize * cached)/1024);

	return 1;
}

void mytop(){
	print_memory();
    getkinfo();
    get_procs();
    if(prev_proc==NULL)
        get_procs();
    
    print_procs(prev_proc,proc,1);
    
}

