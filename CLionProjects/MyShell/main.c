#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<string.h>
#include<ctype.h>
#include<fcntl.h>
#include <signal.h>

//mytop命令需要的宏和定义
#include <pwd.h>
#include <curses.h>
#include <limits.h>
#include <termcap.h>
#include <termios.h>
#include <time.h>
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
//进程结构体
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

#define MAX 30

unsigned int nr_procs,nr_tasks;
int nr_total;

char *lines[MAX];//储存所有命令行
int num=0;
//储存命令行
struct commend{
    int number;
    char *com[MAX];
};

void type_prompt();
int parse_commend(struct commend* commends,int *background);//解析命令
void shell_commend(struct commend* commends);
void program_commend(struct commend* commends,int background);

static inline u64_t make64(unsigned long lo, unsigned long hi);
void parse_file(pid_t pid);
void parse_dir(void);
u64_t cputicks(struct proc *p1, struct proc *p2, int timemode);
void print_procs(struct proc *proc1, struct proc *proc2, int cputimemode);
void get_procs(void);
int print_memory(void);
void getkinfo(void);
void mytop();

//重定向和管道
void greater(char *argv[],int i);
void less(char *argv[],int i);
void pipeline(char *argv[],int i);

int main(void) {
    int type;//命令的类型 0:program 1:shell
    int background=0;
    struct commend commends;

    while(1) {
        type_prompt();
        type = parse_commend(&commends,&background); //解析命令

        //shell内置命令
        if (type == 1) {
            shell_commend(&commends);
        }
//        program命令
        else{
            program_commend(&commends,background);
        }
    }
    return 0;
}
void type_prompt(){
    printf("myshell@host$: ");
    fflush(stdout);//清空输出缓冲区，并把缓冲区内容输出。
}

int parse_commend(struct commend* commends,int *background){
    char *p=(char*)malloc(sizeof(char)*1024);
    for(int i=0;i<MAX;i++){
        commends->com[i]=NULL;
    }
    char line[1024];
    if(fgets(line,MAX,stdin)==NULL){
        fprintf(stderr,"commend failed");
    }
    strcpy(p,line);
    lines[num++]=p;

    char* start = line;
    start[strlen(start)-1]='\0';
    int shell_index = 0;
    while (*start != '\0')
    {
        while (*start != '\0' && isspace(*start))
        {
            *start = '\0';
            start++;
        }
        commends->com[shell_index++] = start;
        while (*start != '\0' && !isspace(*start))
        {
            start++;
        }
    }
    commends->number=shell_index;
    if (strcmp(commends->com[shell_index-1],"&")==0){
        *background=1;
    }
    char* build_in[]={"cd","history","exit","mytop"};
    for(int i=0;i<4;i++){
        if(strcmp(commends->com[0],build_in[i])==0){
            return 1;
        }
    }
    return 0;
}

void shell_commend(struct commend* commends){
    if(strcmp(commends->com[0],"cd")==0){
        if(chdir(commends->com[1])==-1){
            printf("chdir failed");
        }
    }
    else if(strcmp(commends->com[0],"history")==0){
        int hnum=0;
        if(strcmp(commends->com[1],"")==0){//如果没有输入数字
            hnum=num;
        }
        else{
            hnum=atoi(commends->com[1]);
            if(num<hnum){
                hnum=num;
            }
        }

        for(int i=0;i<hnum;i++){
            printf("%d %s",i+1,lines[i]);
        }
    }
    else if(strcmp(commends->com[0],"exit")==0){
        exit(0);
    }
    else if(!strcmp(commends->com[0],"mytop")){
        mytop();
    }
}

void program_commend(struct commend* commends,int background){
    pid_t pid;
    int status;
    if((pid=fork())<0){
        printf("fork error");
        return;
    }
    else if(pid==0){//子进程
        int i=0;
        int l=0;
        int m=0;
        int p=0;
        for(i=0;i<commends->number;i++){
            if(!strcmp(commends->com[i],">")){
                m=i;
                break;
            }
            else if(!strcmp(commends->com[i],"<")){
                l=i;
                break;
            }
            else if(!strcmp(commends->com[i],"|")){
                p=i;
                break;
            }
        }
        if(m>0){
            greater(commends->com,m);
        }
        if(l>0){
            less(commends->com,l);
        }
        if(p>0){
            pipeline(commends->com,p);
        }
        if(i==commends->number){
            if (background == 1) {
                commends->com[commends->number-1]=NULL;
                //子进程的标准输入输出映射成dev/null
                int fd=open("/dev/null",O_RDWR);
                dup2(fd,0);
                dup2(fd,1);
                execvp(commends->com[0], commends->com);
                signal(SIGCHLD, SIG_IGN);//SINCHLD忽略此信号，SIN_IGN向内核忽略此信号
            }
            else
                execvp(commends->com[0], commends->com);
        }
        exit(0);
    }

    //父进程
//    if(background==1){
//        return;
//    }
    if(waitpid(pid,&status,0)==-1){
        printf("wait child process error\n");
    }//等待子进程结束
}

void greater(char *argv[],int i){
    argv[i] = NULL;
    int fd = open(argv[i+1], O_WRONLY | O_CREAT, 0777);
    int copyFd = dup2(fd, 1);
    execvp(argv[0], argv);
    exit(0);
}

void less(char *argv[],int i){
    argv[i] = NULL;
    int fd = open(argv[i+1], O_RDONLY  , 0777);//只读
    int copyFd = dup2(fd, 0);
    close(fd);
    execvp(argv[0], argv);
    exit(0);
}

void pipeline(char* argv[],int i){
    char **argv_1=&argv[0];//第一条命令
    argv[i]=NULL;          //|的位置
    char **argv_2=&argv[i+1];//第二条指令
    int pid2;
    int status;
    //创建管道
    int fd[2];
    pipe(&fd[0]);
    if((pid2=fork())==0){
        close(fd[0]);//进程1不需要读
        close(1);//关掉进程1的标准输出
        dup(fd[1]);//将标准输出指向fd[1]
        close(fd[1]);//不再需要此文件描述符
        execvp(argv_1[0],argv_1);
    }
    if(fork()==0){
        //子进程
        close(fd[1]);//进程2不需要向管道中写
        close(0);//关掉进程2的标准输入
        dup(fd[0]);//将标准输入指向fd[0]
        close(fd[0]);//不再需要此文件描述符
        execvp(argv_2[0],argv_2);
        waitpid(pid2,&status,0);//等待输入端输入后再退出
    }
    //关掉子进程的管道输入输出
    close(fd[0]);
    close(fd[1]);
    //等待两个子进程执行结束
    wait(NULL);
    wait(NULL);
    exit(0);

}

struct tp {
    struct proc *p;//进程指针p
    u64_t ticks;//滴答
};

void mytop(){
    print_memory();//输出内存信息，并且得到总进程数
    getkinfo();//查看进程和任务数量
    get_procs();//将所有需要的信息放在结构体数组proc[]中，每个元素都是一个进程结构体
    if(prev_proc==NULL)
        get_procs();//？
    print_procs(prev_proc,proc,1);//输出CPU使用时间

}

int print_memory(void){
    FILE *fp;
    unsigned int pagesize;
    unsigned long total,free,largest,cached;
    if((fp=fopen("/proc/meminfo","r"))==NULL){
        printf("open /proc/meminfo error");
        return 0;
    }
    if (fscanf(fp, "%u %lu %lu %lu %lu", &pagesize, &total, &free,
               &largest, &cached) != 5) {
        fclose(fp);
        return 0;
    }
    fclose(fp);

    printf("main memory:%ldK total,%ldk free,%ldk cached\n",
           (pagesize*total)/1024,(pagesize*free)/1024,(pagesize*cached)/1024);
    return 1;
}

void getkinfo(void){
    FILE *fp;
    if((fp=fopen("/proc/kinfo","r"))==NULL){
        fprintf(stderr,"opening kinfo failed\n");
        exit(1);
    }
    if(fscanf(fp,"%u %u",&nr_procs,&nr_tasks)!=2){
        fprintf(stderr,"reading kinfo failed");
        exit(1);
    }
    fclose(fp);
    nr_total=(int)(nr_procs+nr_tasks);
}

void get_procs(){//将所有需要的信息放在结构体数组proc[]中，每个元素都是一个进程结构体
    struct proc *p;
    int i;
    p=prev_proc;
    prev_proc=proc;//记录当前的进程数，赋值给prev_proc
    proc=p;//？

    if(proc==NULL){
        proc=malloc(nr_total* sizeof(proc[0]));
        if(proc==NULL){//malloc失败
            fprintf(stderr,"Out of memory!\n");
            exit(1);
        }
    }
    for(i=0;i<nr_total;i++){
        proc[i].p_flags=0;//初始化
    }
    parse_dir();//获取/proc/下的所有进程pid
}

void parse_dir(void){//获取/proc/下的所有进程pid
    DIR *p_dir;
    struct dirent *p_ent;//?
    pid_t pid;
    char* end;

    if((p_dir=opendir("/proc/"))==NULL){
        perror("opendir on /proc/");
        exit(1);
    }
    for(p_ent=readdir(p_dir);p_ent!=NULL;p_ent=readdir(p_dir)){//readdir()返回参数dir 目录流的下个目录进入点。
        pid=strtol(p_ent->d_name,&end,10);//以base10将p_ent->d_name(文件名)转换为长整数型
        if(!end[0]&&pid!=0){
            pronum+=1;
            parse_file(pid);//获取每一个进程的信息，读取/proc/pid/psinfo文件
        }
    }
    closedir(p_dir);
}

void parse_file(pid_t pid){
    char path[PATH_MAX],name[256],type,state;
    int version,endpt,effuid;
    unsigned long cycles_hi,cycles_lo;
    FILE *fp;
    struct proc *p;
    int slot;
    int i;

    sprintf(path,"/proc/%d/psinfo",pid);//根据pid找到文件
    if((fp=fopen(path,"r"))==NULL){
        return;
    }
    if(fscanf(fp,"%d",&version)!=1){
        fclose(fp);
        return;
    }
    if(version!=0){//判断version是否为1，如果不是该进程不需要记录
        fputs("procfs version mismatch!\n",stderr);
        exit(1);
    }
    if(fscanf(fp," %c %d",&type,&endpt)!=2){//format前面有一个空格
        fclose(fp);
        return;
    }

    slot=SLOT_NR(endpt);//?判断出来大于nr_total
    slot=slot_a++;//改变slot的赋值

    if(slot<0||slot>=nr_total){
        fprintf(stderr,"top: unreasonable endpoint number %d\n", endpt);
        fclose(fp);
        return;
    }
    p=&proc[slot];//slot是该进程结构体在数组中的位置

    if(type==TYPE_TASK)
        p->p_flags|=IS_TASK;
    else if (type==TYPE_SYSTEM)
        p->p_flags|=IS_SYSTEM;

    p->p_endpoint=endpt;
    p->p_pid=pid;

    if(fscanf(fp,"%255s %c %d %d %llu %*u %lu %lu",name,&state,&p->p_blocked,
            &p->p_priority,&p->p_user_time,&cycles_hi,&cycles_lo)!=7){
        fprintf(stderr,"fscanf pidinfo error\n");
        fclose(fp);
        return;
    }

    strncpy(p->p_name,name, sizeof(p->p_name)-1);
    p->p_name[sizeof(p->p_name)-1]=0;

    if(state!=STATE_RUN){
        p->p_flags|=BLOCKED;
    }
    p->p_cpucycles[0]=make64(cycles_lo,cycles_hi);
    p->p_memory=0L;//?

    if (!(p->p_flags & IS_TASK)) {
        int j;
        if ((j=fscanf(fp, " %lu %*u %*u %*c %*d %*u %u %*u %d %*c %*d %*u",
                      &p->p_memory, &effuid, &p->p_nice)) != 3) {
            fclose(fp);
            return;
        }
        p->p_effuid = effuid;
    } else p->p_effuid = 0;

    for(i=1;i<CPUTIMENAMES;i++){//三个CPUTIMENAMES
        if(fscanf(fp,"%lu %lu",&cycles_hi,&cycles_lo)==2){
            p->p_cpucycles[i]=make64(cycles_lo,cycles_hi);//拼接成64位
        }
        else{
            p->p_cpucycles[i]=0;
        }
    }

    if((p->p_flags&IS_TASK)){
        if(fscanf(fp,"%lu",&p->p_memory)!=1){
            p->p_memory=0;
        }
    }
    p->p_flags|=USED;
    fclose(fp);
}

u64_t cputicks(struct proc *p1, struct proc *p2, int timemode){//计算每个进程的滴答数
    //通过p1和当前进程p2作比较，如果endpoint相等，则在循环中分别计算
    //滴答不是结构体中的滴答，因为在写文件时需要更新。
    // 需要通过当前进程和该进程一起计算。？？
    int i;
    u64_t t=0;
    for(i=0;i<CPUTIMENAMES;i++){
        if(!CPUTIME(timemode,i))
            continue;
        if(p1->p_endpoint==p2->p_endpoint){// p_endpoint 尾指针？？
            t=t+p2->p_cpucycles[i]-p1->p_cpucycles[i];
        }
        else{
            t=t+p2->p_cpucycles[i];
        }
    }
    return t;
}

void print_procs(struct proc *proc1, struct proc *proc2, int cputimemode){
    int p, nprocs;
    u64_t idleticks=0;
    u64_t kernelticks=0;
    u64_t systemticks=0;
    u64_t userticks=0;
    u64_t total_ticks=0;

    static struct tp *tick_procs=NULL;//创建tp的结构体数组tick_procs

    if(tick_procs==NULL){
        tick_procs=malloc(nr_total * sizeof(tick_procs[0]));
        if(tick_procs==NULL){
            fprintf(stderr,"Out of memory!\n");
            exit(1);
        }
    }

    for(p=nprocs=0;p<nr_total;p++){//对所有的进程计算ticks
        u64_t uticks;
        if(!(proc2[p].p_flags & USED)){
            continue;
        }
        tick_procs[nprocs].p=proc2+p;
        tick_procs[nprocs].ticks=cputicks(&proc1[p],&proc2[p],cputimemode);
//        printf("ticks: %llu",tick_procs[nprocs].ticks);
        uticks=cputicks(&proc1[p],&proc2[p],1);
        total_ticks=total_ticks+uticks;

        if(!(proc2[p].p_flags & IS_TASK)){
            if(proc2[p].p_flags & IS_SYSTEM){
                systemticks=systemticks+tick_procs[nprocs].ticks;
            }
            else
                userticks=userticks+tick_procs[nprocs].ticks;
        }
        nprocs++;
    }
//    printf("666");
    if(total_ticks==0)
        return;
    printf("CPU used:%6.2f%%\n",100.0*(systemticks+kernelticks+userticks)/total_ticks);
//    printf("777");
}

static inline u64_t make64(unsigned long lo, unsigned long hi)
{
    return ((u64_t)hi << 32) | (u64_t)lo;
}

