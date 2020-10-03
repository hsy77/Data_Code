#include <iostream>
#include <fstream>
#include "graph.h"
using namespace std;
int main() {
    graph relation;
    ifstream f("C:\\Users\\rain\\Desktop\\Dase_DataStructure-master\\3.txt");
    int index=1;
    string s;
    if (f){
        while(getline(f, s)) {
            if ((index<=relation.col()+2) &&s.empty()) {
                index++;
                continue;
            }
            if (s.empty()){
                break;
            }
            if (index == 1) {
                index++;
                relation.num(s);
            }
            else if (index == 2) {
                index++;
                relation.find_node(s);
            }
            else {
                if (index<=relation.col()+2 ){
                index++;
                relation.graph_init(s);
            }
                else{
                    index++;
                    relation.name_init(s);
                }
            }
        }
    }
    relation.sort();
    relation.print();
    return 0;
}