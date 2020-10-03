#include <stdio.h>
int main()
{
   int x,m,n,i,j;
   for (i=1;i<=168/2;i++){
       if (168%i==0){
           j=168/i;
       if ((i>j)&&(i%2==0)&&(j%2==0)){
           n=(i-j)/2;
           x=n*n-100;
           printf("x=%d\n",x);
        }
    }
         }
         return 0;
   }


