#include <stdio.h>
#include <math.h>
int main(){
	int i; 
    char *poem[4]={"一叶轻舟","帆梢轻握","风纤碧波","顺水任从"};
	char mean[10];
	for (i=0;i<4;i++){
		mean[2*i]=*poem[i];
		mean[2*i+1]=*(poem[i]+1);
	}
	mean[2*i]='\0';
	printf("%s",mean);
    return 0;
}

