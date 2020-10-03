#include <iostream>
#include "listUDG.h"
int main()
{
    // 顶点
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    // 边
    EData *edges[] = {
            // 起点 终点 权
            new EData('A', 'B', 12),
            new EData('A', 'F', 16),
            new EData('A', 'G', 14),
            new EData('B', 'C', 10),
            new EData('B', 'F',  7),
            new EData('C', 'D',  3),
            new EData('C', 'E',  5),
            new EData('C', 'F',  6),
            new EData('D', 'E',  4),
            new EData('E', 'F',  2),
            new EData('E', 'G',  8),
            new EData('F', 'G',  9),
    };
    int vlen = sizeof(vexs)/sizeof(vexs[0]);
    int elen = sizeof(edges)/sizeof(edges[0]);
    ListUDG* pG;

    // 自定义"图"(输入矩阵队列)
    //pG = new ListUDG();
    // 采用已有的"图"
    pG = new ListUDG(vexs, vlen, edges, elen);

    //pG->print();   // 打印图
    //pG->DFS();     // 深度优先遍历
    //pG->BFS();     // 广度优先遍历
    //pG->prim(0);   // prim算法生成最小生成树

    pG->kruskal();   // Kruskal算法生成最小生成树

    return 0;
}