#include <stdio.h>
int main(){
    int i,j,M,N;
    int m[20];
    int n[20];
    int ret[20];
    
    scanf("%d",&M);
    for (i=0;i<M;i++){
        scanf("%d",&m[i]);
    }
    scanf("%d",&N);
    for (i=0;i<N;i++){
        scanf("%d",&n[i]);
    }
    
    int flag=1;
    int k=0;
    for (i=0;i<M;i++){
    	flag=1;
        for (j=0;j<N;j++){
            if (m[i]==n[j]){
                flag=0;
                break;
            }
        }
        if (flag){
            ret[k]=m[i];
            k++;
        }
    }
    for (i=0;i<N;i++){
    	flag=1;
        for (j=0;j<M;j++){
            if (n[i]==m[j]){
                flag=0;
                break;
            }
        }
        if (flag){
            ret[k]=n[i];
            k++;
        }
    }
    if (k==1) 
    printf("%d",ret[0]);
    else {
    	printf("%d ",ret[0]);
    	for (i=1;i<k;i++){
    	flag=1;
    	for (j=0;j<i;j++){
    		if (ret[i]==ret[j]){
    			flag=0;
    			break;
			}
		}
		if (flag){
			printf("%d",ret[i]);
    	if (i != k-1) printf(" ");
		}
}
	}
    
    return 0;
}

