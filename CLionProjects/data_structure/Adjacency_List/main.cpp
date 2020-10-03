#include <iostream>
#include "Adjacency_list.h"
int main() {
    Adjacency_list adj_list;
    char vexs[]={'0','1','2','3','4','5'};
    Gdata edge[]={{'0','1',6},
                    {'0','3',4},
                    {'1','3',7},
                    {'1','4',7},
                    {'1','2',10},
                    {'2','3',8},
                    {'2','4',5},
                    {'2','5',6},
                    {'3','4',12},
                    {'4','5',7}

    };
    int vlen = sizeof(vexs)/sizeof(vexs[0]);
    int elen = sizeof(edge)/sizeof(edge[0]);
    adj_list.init_list(vexs,edge,vlen,elen);
//    adj_list.DFS_graph();
//    adj_list.BFS_graph();
    adj_list.kruskal();
    return 0;
}