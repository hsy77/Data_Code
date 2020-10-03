//
// Created by rain on 2019/12/5.
//
#ifndef INC_2_1_BINARY_TREE_H
#define INC_2_1_BINARY_TREE_H

#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode();
};
class binary_tree {
public:
    BinaryTreeNode* build_tree(string &s);
    void search_path(BinaryTreeNode* aroot,int target);
    bool flag();
private:
    vector<int> q_data;
    bool flag_= false;
};


#endif //INC_2_1_BINARY_TREE_H
