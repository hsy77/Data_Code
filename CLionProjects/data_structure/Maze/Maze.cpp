//
// Created by rain on 2019/9/27.
//
#include <iostream>
#include "Maze.h"
using namespace std;

Maze::Maze() {

}

void Maze::initMaze(int *p_maze,int n_colrow_) {
    int i, j;
    for (i = 0; i < n_colrow_ + 2; i++) {
        matrix_[0][i] = 1;
        matrix_[n_colrow_ + 1][i] = 1;
        matrix_[i][0] = 1;
        matrix_[i][n_colrow_ + 1] = 1;
    }
    for (i = 1; i < n_colrow_ + 1; i++) {
        for (j = 1; j < n_colrow_ + 1; j++) {
            matrix_[i][j] = p_maze[n_colrow_ * (i - 1) + j - 1];
        }
    }
    n_colrow=n_colrow_;
    pstart.col = 1;
    pstart.row = 1;
    cout << "please print row and col of the ehd" << endl;
    cin >> pend.row;
    cin >> pend.col;

    for (i = 0; i < n_colrow_ + 2; i++) {
        for (j = 0; j < n_colrow_ + 2; j++) {
            PathBFS_[i][j].row=0;
            PathBFS_[i][j].col=0;
        }
    }
}

bool Maze::cango_(int row,int col){
    return !(matrix_[row][col]);
}

void Maze::PrintBfsPath(){
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    point next,cur;
    cout<<pstart.row<<","<<pstart.col<<endl;
    maxqueue_.append(pstart);
    visitedBFS_[pstart.row][pstart.col]=1;

    while (!(maxqueue_.empty())){
        maxqueue_.serve_and_retrieve(cur);  //可以直接把结构体传出来吗？应该是可以的，找找bug
        if(cur.row==pend.row && cur.col==pend.col){
            cout<<"reached the end of the maze"<<endl;
        }
        else{
                for(int i=0;i<4;i++){
                    next.row=cur.row+dir[i][0];
                    next.col=cur.col+dir[i][1];
                    if (cango_(next.row,next.col)&&visitedBFS_[next.row][next.col]==0){
                        maxqueue_.append(next);
                        visitedBFS_[next.row][next.col]=1;
                        PathBFS_[next.row][next.col].row=cur.row;
                        PathBFS_[next.row][next.col].col=cur.col;//因为数组名只是代表数组第一个元素的地址的值，比如数组 int a[10]是不能作为左值的，不能给它赋值。在任何时候都不能把数组名直接放在等号的左边
                    }
                }
        }
    }

    while (cur.row!=pstart.row||cur.col!=pstart.col){
         //从后往前输出
        cout<<cur.row<<","<<cur.col<<"->";
        cur.row=PathBFS_[cur.row][cur.col].row;
        cur.col=PathBFS_[cur.row][cur.col].col;
    }

}
void Maze::printMaze(){
    for (int i=1;i<n_colrow+1;i++){
        for (int j=1;j<n_colrow+1;j++){
            cout<<matrix_[i][j]<<' ';
        }
        cout<<endl;
    }
}
