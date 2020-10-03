#include <stdio.h>
int main()
{
    int i,j,k,n=0;
    for (i=1;i<=4;i++){
        n=n+i*100;
        for (j=1;j<=4;j++){
            n=n+j*10;
            for (k=1;k<=4;k++){
                n=n+k;
                if ((i!=j)&&(i!=k)&&(j!=k)){
                    printf("%d\n",n);
                }
                n=n-k;
            }
            n=n-j*10;
        }
        n=n-i*100;
    }
	return 0;
}

