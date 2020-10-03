#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
//#include<sys/wait.h>
#include<string.h>
#include<ctype.h>
#include<fcntl.h>
#include <signal.h>

unsigned int nr_procs,nr_tasks;
int nr_total;

int print_memory(void){
    FILE *fp;
    unsigned int pagesize;
    unsigned long total,free,cached;
    if((fp=fopen("/proc/meminfo","r"))==NULL)
        return 0;
    if(fscanf(fp,"%u %lu %lu %lu",&pagesize,&total,&free,&cached)!=4){
        fclose(fp);
        return 0;
    }
    fclose(fp);

    printf("main memory:%ldK total,%ldk free,%ldk cached\n",
           (pagesize*total)/1024,(pagesize*free)/1024,(pagesize*cached)/1024);
    return 1;
}

int main(){
    print_memory();
}