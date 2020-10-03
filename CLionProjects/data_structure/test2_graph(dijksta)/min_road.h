//
// Created by rain on 2019/12/8.
//

#ifndef INC_3_2_MIN_ROAD_H
#define INC_3_2_MIN_ROAD_H
const int max_size=100000;
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
using namespace std;
struct pair_node{
    int y;
    int len;
};
class min_road {
public:
    void graph(string s);
    void Dijksta();
    int length();
    vector<string> split(string s,char c,vector<string> v);
    void init_set();
private:
    multimap <int,pair_node> list;
    vector<string> node;
    int count=1;
    int size_;
    set<int> select;
    set<int> unselect;
    int dist[max_size];
    int path[max_size];
};


#endif //INC_3_2_MIN_ROAD_H
