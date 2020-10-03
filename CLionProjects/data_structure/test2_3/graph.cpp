//
// Created by rain on 2019/12/13.
//

#include "graph.h"
void graph::num(string s) {
    vector<string> num;
    num=splitC.split(s,patten);
    int node=stoi(num[0]);
    node_num=node;
    int vec=stoi(num[1]);
    vec_num=vec;
}

void graph::find_node(string s) {
    node=splitC.split(s,patten);
}

int graph::col() {
    return vec_num;
}

void graph::graph_init(string s) {
    vector<string> v;
    v=splitC.split(s,patten);
    list.insert(pair<string,string>(v[0],v[1]));
    list.insert(pair<string,string>(v[1],v[0]));
}

void graph::name_init(string s) {
    name[name_num]=s;
    name_num++;
}

void graph::sort() {
    for(auto it=list.begin();it!=list.end();it++){
        sort_list.insert(pair<string,string>(it->second,it->first));
    }
}

void graph::print() {
    for (int i=0;i<node.size();i++){
        string name=node[i];
        multimap<string,string>::iterator iterm;
        iterm=sort_list.find(name);
        cout<<name<<' ';
        for (int j = 0; j < list.count(name); j++,iterm++) {
            cout<<iterm->second<<' ';
        }
        cout<<endl;
    }
}