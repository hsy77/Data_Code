#include <stdio.h>
int main(){
	int n;
	int i;
	int k;
	int index;
	int temp; 
	scanf("%d",&n);
	int a[10];
	for (i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for (k=0;k<n-1;k++){
		index=k;
		for(i=k+1;i<n;i++){
			if (a[i]<a[index]){
				temp=a[i];
				a[i]=a[index];
				a[index]=temp;
			}
		}
	}
	for (i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
} 
