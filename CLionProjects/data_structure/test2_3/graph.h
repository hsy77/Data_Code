//
// Created by rain on 2019/12/13.
//

#ifndef TEST2_3_GRAPH_H
#define TEST2_3_GRAPH_H

#include "split.h"
#include <map>
#include <cstring>
#include <iostream>
using namespace std;
class graph {
public:
    void num(string s);
    void find_node(string s);
    int col();
    void graph_init(string s);
    void sort();
    void name_init(string s);
    void print();
private:
    char patten=' ';
    int node_num;
    int vec_num=10;
    vector<string> node;
    vector<string> name;
    int name_num=0;
    multimap <string,string> list;
    multimap <string,string> sort_list;
    split_c splitC;
};


#endif //TEST2_3_GRAPH_H
