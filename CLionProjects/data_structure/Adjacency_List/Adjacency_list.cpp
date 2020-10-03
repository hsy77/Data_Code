//
// Created by rain on 2019/11/25.
//

#include "Adjacency_list.h"
#include <iostream>
using namespace std;
void Adjacency_list::init_list(char vexs[],Gdata edges[],int vlen,int elen){
    max_size=vlen;
    edges_len=elen;
    data=vexs;
    for (int i=0;i<elen;i++){
        edge_.push_back(edges[i]);
        pair_node node;
        node.c=edges[i].end;
        node.n=edges[i].weight;
        list.insert(pair<char,pair_node>(edges[i].start,node));
        node.c=edges[i].start;
        list.insert(pair<char,pair_node>(edges[i].end,node));
    }

}

void Adjacency_list::bool_list() {
    for (int i = 0; i < max_size; i++) {
        visited.insert(pair<char, bool>(data[i], false));
    }
}

void Adjacency_list::DFS_graph() {
    bool_list();
    for (int i=0;i<max_size;i++){
        char c=data[i];
        if (!visited[c]){
            traverse(c);
        }
    }
}

void Adjacency_list::traverse(char m) {
    visited[m]= true;
    cout<<m<<' ';
    multimap<char,pair_node>::iterator iterm;
    iterm=list.find(m);
    for (int i = 0; i < list.count(m); i++,iterm++) {
        char n=iterm->second.c;
        if (!visited[n]){
            traverse(n);
        }
    }
}

void Adjacency_list::BFS_graph() {
    queue<char> q;
    bool_list();
    for (int i=0;i<max_size;i++){ //以防有未连通的点
        char c=data[i];
        if (!visited[c]){
            q.push(c);
            visited[c]= true;
            while (!q.empty()){
                char m=q.front();
                cout<<m<<' ';
                q.pop();
                multimap<char,pair_node>::iterator iterm;
                iterm=list.find(m);
                for (int i = 0; i < list.count(m); i++,iterm++) {
                    char n=iterm->second.c;
                    if (!visited[n]){
                        q.push(n);
                        visited[n]= true;
                    }
                }
            }
        }
    }
}


bool Adjacency_list::cmp(Gdata a, Gdata b) {
    return a.weight<b.weight;
}
//记Graph中有v个顶点，e个边
//新建图Graphnew，Graphnew中拥有原图中相同的e个顶点，但没有边
//将原图Graph中所有e个边按权值从小到大排序
//循环：从权值最小的边开始遍历每条边 直至图Graph中所有的节点都在同一个连通分量中
//if 这条边连接的两个节点于图Graphnew中不在同一个连通分量中
//             添加这条边到图Graphnew中
void Adjacency_list::sortEdges() {
    int i,j;
    for (i=0;i<edges_len;i++){
        for (j=0;j<edges_len;j++){
            if (edge_[i].weight<edge_[j].weight){
                swap(edge_[i],edge_[j]);
            }
        }
    }
}

char Adjacency_list::getEnd(map<char,char> vends,char a) {
    while (vends[a]!=a){
        a=vends[a];
    }
    return a;
}
void Adjacency_list::kruskal() {
    int i,length;
    char p1,p2;
    int index=0; //rets数组的索引
    Gdata rets[max_size];
    map<char,char> vends;
    for (i=0;i<max_size;i++){
        vends.insert(pair<char,char>(data[i],data[i]));
    }

    sortEdges(); //对所有边排序
    for (i=0;i<edges_len;i++){
        p1=getEnd(vends,edge_[i].start);
        p2=getEnd(vends,edge_[i].end);
        if(p1!=p2){
            vends[p1]=p2;
            rets[index++]=edge_[i];
        }
    }
    //统计并打印“kruskal最小生成树”的信息
    length=0;
    for (i=0;i<index;i++){
        length+=rets[i].weight;
    }
    cout<<"kruskal="<<length<<":";
    for (i=0;i<index;i++){
        cout<<"("<<rets[i].start<<","<<rets[i].end<<")";
    }
    cout<<endl;
}