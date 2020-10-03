#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int count=0,flag,mynumber,yournumber;
    srand(time(0));
    mynumber=rand()%100+1;
    flag=0;
    while (count<7){
        printf("enter yournumber:");
        scanf("%d",&yournumber);
        count++;
        if (yournumber==mynumber){
            printf("lucky you\n");
            flag=1;
            break;
        }
        else{
            if (yournumber>mynumber){
                printf("too larger\n");
            }
            else printf("too smaller\n");
        }
    }
    if (flag==0) printf("my number=%d,game over\n",mynumber);
    return 0;
   }

