//
// Created by rain on 2019/11/13.
//

#ifndef TREE_SEARCH_TREE_H
#define TREE_SEARCH_TREE_H
#include <stack>
#include <string>
using namespace std;
enum Error_code{success,not_present};
struct TreeNode{
    TreeNode* leftChild;
    char data;
    TreeNode* rightChild;
};

class Search_tree {
public:
    void BuildTree_postorder(TreeNode* &aroot,string &postorder,int &index);
    void Search_Node(TreeNode* &aroot,char target);
    void print_route();
    Error_code search_rem(TreeNode* &aroot,char rm_target);
    Error_code Remove_Node(TreeNode* &sub_root);
    void inorder(TreeNode* &aroot);
private:
    stack<char> tree_node_;
};


#endif //TREE_SEARCH_TREE_H
