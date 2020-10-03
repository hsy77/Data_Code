//
// Created by rain on 2019/12/8.
//

#include "min_road.h"
#include <cstring>
void min_road::graph(string s) {
    vector<string> vec;
    if (count==1){
        node=split(s,' ',vec);
    }
    else{
        vec=split(s,' ',vec);
        pair_node node;
        int x=stoi(vec[0]);
        int y=stoi(vec[1]);
        node.y=y;
        node.len=stoi(vec[2]);
        list.insert(pair<int,pair_node>(x,node));
        node.y=x;
        list.insert(pair<int,pair_node>(y,node));
    }
    count++;
}

vector<string> min_road::split(string s,char c,vector<string> v){
    string q;
    for (int i=0;i<s.size();i++){
        if (s[i]!=c){
                q.push_back(s[i]);
            }
        else {
            v.push_back(q);
            q = "";
        }
    }
    v.push_back(q);
    return v;
}
void min_road::init_set() {
    for (int i=0;i<node.size();i++){
        unselect.insert(stoi(node[i]));
    }
    select={};
    size_=node.size();
    for (int i=0;i<=size_;i++){
        dist[i]=1001;
    }
}
void min_road::Dijksta() {
    init_set();
    unselect.erase(1);
    select.insert(1);
    dist[1] = 0;
    multimap<int, pair_node>::iterator iterm;
    iterm = list.find(1);
    for (int i = 0; i < list.count(1); i++, iterm++) {
        int y = iterm->second.y;
        dist[y] = iterm->second.len;
    }
    while (!unselect.empty()) {
        int i=0;
        int min=0;
        for (i = 1; i <= size_; i++) {
            if (unselect.count(i)) {
                min = i;
                break;
            }
        }
        for (i = min+1; i <= size_; i++) {
            if (unselect.count(i) && dist[i] < dist[min]) {
                min = i;
            }
        }
        unselect.erase(min);
        select.insert(min);
        multimap<int, pair_node>::iterator iterm;
        iterm = list.find(min);
        for (int j = 0; j < list.count(min); j++, iterm++) {
            int y = iterm->second.y;
            int len = iterm->second.len;
            if ((dist[min] + len) < dist[y]) {
                dist[y] = dist[min] + len;
            }
        }
    }
}

int min_road::length() {
    int n=stoi(node[size_-1]);
    return dist[n];
}