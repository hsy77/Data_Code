//
// Created by rain on 2019/9/6.
//

//建立一个二维数组a[][](自己决定）
//cin y continue, n break;

//判断 n(1)<=1 a[i][j]=0;
//n(1)>=4,a[i][j]=0;
//n(1)==3,a[i][j]=1;
//
#include "Life.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
void Life::initialize(){
    int i,j;
    int x;
    for (i=0;i<maxrow + 2;i++) {
        for (j = 0; j < maxcol + 2; j++) {
            if (j==0 || j==61 ||i==0 ||i==21 ){
                grid[i][j]=0;
            }
            else{
                x=rand()%10;
                if (x>=5 ){
                    grid[i][j]=1;
                }
                else grid[i][j]=0;
            }
        }
    }
}

void Life::print(){
    int i,j;
    for (i=1;i<maxrow + 1;i++){
        for (j=1;j<maxcol + 1;j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}

int Life:: neighbor_count(int row, int col){
    int n;
    n=grid[row-1][col-1]+grid[row-1][col]+
       grid[row-1][col+1]+grid[row][col-1]+grid[row][col+1]+
       grid[row+1][col-1]+grid[row+1][col]+grid[row+1][col+1];
    return n;
}
void Life::update() {
    //用另一个数组表示更新后的数组，在放进原来的数组里（题目理解错误）
    int i, j;
    for (i = 1; i < maxrow + 1; i++) {
        for (j = 1; j < maxcol + 1; j++) {
            if ((neighbor_count(i,j)<=1) or
            (neighbor_count(i,j)>=4))
                grid[i][j]=0;
            if (neighbor_count(i,j)==3)
                grid[i][j]=1;
        }
    }
}
