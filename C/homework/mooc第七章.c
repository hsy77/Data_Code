#include <stdio.h>
#include <math.h>
int isprime(int n);
int main() {
	int i,n;
	scanf("%d",&n);
	printf("%d=",n);
	for (i=2;i<=n;i++){
	    while (n%i==0) {
	        if (isprime(i)){
	            printf("%d",i);
	            
	            }
	        if (n/i!=1) printf("x");
	        n=n/i;
	    }
	}
	return 0;
}
int isprime(int n){
    int i,flag;
    for (i=2;i<n;i++){
        flag=1;
        if (n%i==0) {
            flag=0;
            break;
        }
    }
    return flag;
}

