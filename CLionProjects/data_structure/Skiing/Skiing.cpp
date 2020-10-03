//
// Created by rain on 2019/10/6.
//
#include "Skiing.h"
#include <iostream>
using namespace std;

Skiing::Skiing() {

}

void Skiing::init_matrix(int row,int col){
    int i,j;
    for (i=1;i<row+1;i++){
        for (j=1;j<col+1;j++){
            cin>>matrix_[i][j];
        }
    }
    for (i=0;i<row+2;i++){
        matrix_[i][0]=10001;
        matrix_[i][col+1]=10001;
    }
    for (i=0;i<col+2;i++){
        matrix_[0][i]=10001;
        matrix_[row+1][i]=10001;
    }
    row_=row;
    col_=col;
//    测试二维数组
//    {
//        for (i=0;i<row+2;i++){
//            for (j=0;j<col+2;j++){
//                cout<<matrix_[i][j]<<" ";
//            }
//            cout<<endl;
//        }
//    }
}

bool Skiing::cango(pos now,pos next) {
    return matrix_[next.row][next.col]<matrix_[now.row][now.col];
}

//BFS 队列
void Skiing:: BFSLength(int row,int col) {
    pos now, next;
    now.row = row;
    now.col = col;
    int count = 0;//记走了多长
    int add = 0;//记每个数周围多少个加了进去
    int step_[maxrowcol + 2][maxrowcol + 2] = {0};
    int dir[4][2] = {{1,  0},
                     {0,  1},
                     {-1, 0},
                     {0,  -1}};
    skiqueue_.push(now);
    while (!skiqueue_.empty()) {
        now = skiqueue_.front();
        skiqueue_.pop();
        for (int i = 0; i < 4; i++) {
            next.row = now.row + dir[i][0];
            next.col = now.col + dir[i][1];
            if (cango(now, next)) {
                skiqueue_.push(next);
                step_[next.row][next.col] = step_[now.row][now.col] + 1;
                if (step_[next.row][next.col] > max_) {
                    max_ = step_[next.row][next.col];
                }
            }
        }
    }
    return ;
}

void Skiing:: BFS_maxlength(){
    int i,j;
    for (i=1;i<row_+1;i++){
        for (j=1;j<col_+1;j++){
            BFSLength(i,j);
        }
    }
    cout<<"max length="<<max_<<endl;
}

//DFS 递归
void Skiing::DFS_(pos now,int step){
    int i;
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    pos next;
    for (i=0;i<4;i++){
            next.row = now.row + dir[i][0];
            next.col = now.col + dir[i][1];
            if (cango(now,next)){
                //step++;                   为什么这样每次递归后step会变化？
                DFS_(next,step+1);
            }
        }
    if (i==4) {
        if (step>max_) max_=step;
        return;
    }
}

void Skiing::DFSLength(int row,int col){
    int step=0;
    pos now;
    now.row=row;
    now.col=col;
    DFS_(now,step);
    return;
}

void Skiing::DFS_maxlength(){
    int i,j;
    for (i=1;i<row_+1;i++){
        for (j=1;j<col_+1;j++){
            DFSLength(i,j);
            //cout<<"max length="<<max_<<endl;
        }
    }
    cout<<"max length="<<max_<<endl;
}
