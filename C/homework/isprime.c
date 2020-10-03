#include <stdio.h>

int main()
{
    int i,n;
    printf("enter a number=");
    scanf("%d",&n);
    for (i=2;i<=n/2;i++){
        if (n%i==0)
        break;
    }
    if (i>n/2 && n!=1){
        printf("%d is a prime number",n);
    }
    else {
        printf("no");
    }
    return 0;
   }


