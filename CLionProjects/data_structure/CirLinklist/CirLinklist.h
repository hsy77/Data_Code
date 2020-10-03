//
// Created by rain on 2019/9/20.
//
#include <iostream>
using namespace std;
#ifndef CIRLINKLIST_CIRLINKLIST_H
#define CIRLINKLIST_CIRLINKLIST_H

typedef int Node_entry;
struct Node{
    Node_entry entry;
    Node *next;
};

class CirLinklist {
public:
    CirLinklist();
    void create_CirLinklist(int n);
    void append(Node_entry n);
    void delete_CirLinklist(int m);
    Node_entry solve();
private:
    Node *head;
    int count;
};


#endif //CIRLINKLIST_CIRLINKLIST_H
