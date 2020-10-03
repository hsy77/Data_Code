//
// Created by rain on 2019/9/6.
//

#ifndef LIFE_LIFE_H
#define LIFE_LIFE_H


const int maxrow = 20, maxcol = 60;    //  grid dimensions
//const int maxrow = 10, maxcol = 10;
class Life {
public:
    void initialize(); //初始化配置，初始化一个二维数组
    void print(); //输出当前配置（数组状态）
    void update();  //一次迭代
private:
    int grid[maxrow + 2][maxcol + 2];
    int neighbor_count(int row, int col);
};


#endif //LIFE_LIFE_H
