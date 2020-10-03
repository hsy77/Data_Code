#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *match(char*s, char ch);
int main(void){
	char str[80],ch,*p=NULL;
	printf("str=");
	scanf("%s",str);
	getchar();
	ch=getchar();
	if ((p=match(str,ch))!=NULL){
		printf("%s",p);
	}
	else {
		printf("no found");
	}
	return 0;
} 
char *match(char*s, char ch){
	int n;
	while (*s!='\0'){
		if (*s==ch){
		return s;
		} 
		else s++;
	}
	return NULL;
}
