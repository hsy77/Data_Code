#include <stdio.h>
#include <stdlib.h>
void transitive(int mat[][4]);
void mutil(int a[][4],int b[][4]);
void or_mat(int a[][4],int b[][4]);
int main(){
    int matrix[4][4]={1,0,0,1,
                      1,0,1,0,
                      1,1,0,1,
                      0,1,0,0};
	transitive(matrix);
	int i,j;
	for (i=0;i<4;i++){
		for (j=0;j<4;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
void mutil(int a[][4],int b[][4]){
	int c[4][4]={0};
	int i,j,k;
	for (i=0;i<4;i++){
		for (j=0;j<4;j++){
			for (k=0;k<4;k++){
				c[i][j]|=a[i][k] & b[k][j];
			}
		}
	}
	for (int i=0;i<4;i++){
	    for (int j=0;j<4;j++){
	        a[i][j]=c[i][j];
	    }
	}
}
void or_mat(int a[][4],int b[][4]){
	int c[4][4]={0};
	int i,j;
	for (i=0;i<4;i++){
		for (j=0;j<4;j++){
			c[i][j]=a[i][j] | b[i][j];
		}
}
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            b[i][j]=c[i][j];
        }
    }
}
void transitive(int mat[][4]){
    int a[4][4]={0};
    int b[4][4]={0};
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            a[i][j]=mat[i][j];
            b[i][j]=mat[i][j];
        }
    }
	int i;
	for (i=2;i<=4;i++){
		mutil(a,mat);
		or_mat(a,b);
	}
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            mat[i][j]=*(b[i]+j);
        }
    }
}