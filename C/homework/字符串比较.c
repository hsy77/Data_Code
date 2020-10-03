#include <stdio.h>
#include <string.h> 


void fsort (char*color[],int n);

int main()
{
    int i;
    char *pcolor[]={"red","black","green","yellow","blue"};
    fsort(pcolor,5);
    for (i=0;i<5;i++){
    	printf("%s",pcolor[i]);
	}
    return 0;
}
 void fsort (char*color[],int n){
 	int i,j;
 	char*temp;
 	for (i=1;i<n;i++){
 		for (j=0;j<n-i;j++){
 			if (strcmp(color[j],color[j+1])>0){
 				temp=color[j];
 				color[j]=color[j+1];
 				color[j+1]=temp;
			 }
		 }
	 }
 }

