#include <stdio.h>
int main(){
    int m,n;
    int i,j,k;
    int temp;
    int a[6][6];
    scanf("%d %d",&m,&n);
    
    for (i=0;i<n;i++){
    	for (j=0;j<n;j++){
    		scanf("%d",&a[i][j]);
		}
	}
    
    for (i=0;i<n;i++){
    	for (k=0;k<m;k++){               //�ƶ�������˼��һ��������ô����Ȼ��ѭ���� 
    			temp=a[i][n-1];
			for (j=n-1;j>0;j--){        //�����ƶ�һ�� 
    			a[i][j]=a[i][j-1];
			}
			a[i][0]=temp;
		}		
    }
   
    for (i=0;i<n;i++){
    	for (j=0;j<n;j++){
    		printf("%d ",a[i][j]);
		}
		printf("\n");
	}
    return 0;
}


