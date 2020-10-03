#include <stdio.h>
int bsearch(int* p,int n,int x);
int main(){
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int x,m;
	scanf("%d",&x);
	m=bsearch(a,10,x);
	if (m>=0) printf("%d\n",m);
	else printf("no found\n");
	return 0;
}
int bsearch(int* p,int n,int x){
	int low,high, mid;
	low=0;
	high=n-1;
	while (low<=high){
		mid=(low+high)/2;
		if (p[mid]==x) break;
		else if (x<p[mid])
			high=mid-1;
		else low=mid+1; 
	}
	if (low<=high) return mid;
	else return -1;
}
