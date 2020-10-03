//
// Created by rain on 2019/11/25.
//

#ifndef ADJACENCY_LIST_ADJACENCY_LIST_H
#define ADJACENCY_LIST_ADJACENCY_LIST_H
#define INF (~(0x1<<31))
const int MAX=100;
#include <map>
#include <queue>
#include <vector>
using namespace std;
struct Gdata{
    char start;
    char end;
    int weight;

};
struct pair_node{
    char c;
    int n;
};
struct visited{
    char c;
    bool b;
};
class Adjacency_list {
public:
    void init_list(char vexs[],Gdata data_pair[],int vlen,int elen);
    void bool_list();
    void BFS_graph();
    void DFS_graph();
    void traverse(char m);

    bool cmp(Gdata a,Gdata b);
    void sortEdges();
    char getEnd(map<char,char> vends,char a);
    void kruskal();
private:
    multimap <char,pair_node> list;
    vector<Gdata> edge_;
    map <char,bool> visited;
    char *data;
    int max_size;
    int edges_len;
};


#endif //ADJACENCY_LIST_ADJACENCY_LIST_H
