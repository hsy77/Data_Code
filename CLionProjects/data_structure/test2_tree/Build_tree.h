//
// Created by rain on 2019/12/5.
//

#ifndef TREE_TEST_BUILD_TREE_H
#define TREE_TEST_BUILD_TREE_H

#include <iostream>
#include <string>
#include <queue>
using namespace std;
typedef int type;
struct TreeNode{
    type data;
    TreeNode* left;
    TreeNode* right;
    TreeNode();
    TreeNode(type &x);
};

class Build_tree {
public:
//    void build_preorder(TreeNode* &aroot,string &preorder,int &index);//先序
//    void build_postorder(TreeNode* &aroot,string &preorder,int &index);//后序
//    TreeNode* BFS_build(string &bfsorder);//层次遍历
//    void build_PreMidorder(TreeNode* &aroot,string &preorder,string &midorder,int &index,int pstart,int pend);//先序+中序
    void build_preorder(TreeNode* &aroot,vector<string> &preorder,int &index);//先序
//    void build_postorder(TreeNode* &aroot,vector<string> &preorder,int &index);//后序
//    TreeNode* BFS_build(vector<string> &bfsorder);//层次遍历
//    void build_PreMidorder(TreeNode* &aroot,vector<string> &preorder,vector<string> &midorder,int &index,int pstart,int pend);//先序+中序
    void print(TreeNode* aroot);
    void recursive_inorder(TreeNode* sub_root);
    void max_init(TreeNode* aroot);
    void max_sum(TreeNode *aroot);
    void print_max();
private:
    queue<TreeNode*> q;
    int max=0;//先假设为零
    vector<int> v;
};


#endif //TREE_TEST_BUILD_TREE_H
