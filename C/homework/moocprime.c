#include <stdio.h>
int isprime(int x,int knowsprimes[],int count);
int main(void){
    int number=100;
    int prime[100]={2};
    int count=1;
    int i=3;
    while (count<number){
        if (isprime(i,prime,count)){
            prime[count++]=i;
        }
        i++;
    }
    for (i=0;i<number;i++){
        printf("%d",prime[i]);
        if ((i+1)%5) printf("\t");
        else printf("\n");
    }
    return 0;
}
int isprime(int x,int knowsprimes[],int count){
    int ret=1;
    int i;
    for (i=0;i<count;i++){
        if (x%knowsprimes[i]==0){
            ret=0;
            break;
        }
    }
    return ret;
}

