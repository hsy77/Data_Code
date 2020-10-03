//
// Created by rain on 2019/10/6.
//

#ifndef SKIING_SKIING_H
#define SKIING_SKIING_H

#include <iostream>
#include <queue>
using namespace std;
const int maxrowcol=100;

struct pos{
    int row;
    int col;
};
class Skiing {
public:
    Skiing();
    void init_matrix(int row,int col);
    void BFSLength(int row,int col);//求一个位置的最大长度
    void BFS_maxlength();//for循环，把每个位置的最大长度放在矩阵里
    void DFSLength(int row,int col);//递归 求一个位置的最大长度
    void DFS_maxlength();//for循环，把每个位置的最大长度放在矩阵里


private:
    int row_;
    int col_;
    int max_;
    bool cango(pos now,pos next);
    int matrix_[maxrowcol+2][maxrowcol+2];

    int LengthMat_[maxrowcol+2][maxrowcol+2];
    queue<pos> skiqueue_;

    void DFS_(pos cur,int step);
};


#endif //SKIING_SKIING_H
