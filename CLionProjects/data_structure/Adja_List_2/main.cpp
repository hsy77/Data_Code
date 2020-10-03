#include <iostream>
#include "adja_list.h"
int main() {
    //顶点
    type vexs[]={'1','2','3','4','5'};
    //边
    data *edges[]={
            new data('0','1',6),
            new data('0','3',4),
            new data('1','3',7),
            new data('1','4',7),
            new data('1','2',10),
            new data('2','3',8),
            new data('2','4',5),
            new data('2','5',6),
            new data('3','4',12),
            new data('4','5',7),
    };
    int vlen=sizeof(vexs)/ sizeof(vexs[0]);
    int elen= sizeof(edges)/ sizeof(edges[0]);
    //形成图

    return 0;
}