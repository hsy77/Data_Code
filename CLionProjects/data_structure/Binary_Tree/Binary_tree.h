//
// Created by rain on 2019/11/15.
//

#ifndef BINARY_TREE_BINARY_TREE_H
#define BINARY_TREE_BINARY_TREE_H

#include <iostream>
template <class Entry>
struct Binary_node{
    Entry data;
    Binary_node* left;
    Binary_node* right;
    //constructors
    Binary_node();//不带参数的构造函数
    Binary_node(const Entry &x);//带一个参数的构造函数
};
template <class Entry>
Binary_node<Entry>::Binary_node() {
            left=NULL;
            right=NULL;
}
template <class Entry>
Binary_node<Entry>::Binary_node(const Entry &x) {
    data=x;
    left=NULL;
    right=NULL;
}
template <class Entry>
class Binary_tree {
public:
    Binary_tree();
    bool empty() const ;
    void preorder(void (*visit)(Entry &));
    void inorder(void (*visit)(Entry &));
    void postorder(void (*visit)(Entry &));
    int size() const;
    int height() const ;
    void insert(Entry &);

protected:
    void recursive_preorder(Binary_node<Entry>*sub_root, void (*visit)(Entry &));
    void recursive_inorder(Binary_node<Entry>*sub_root, void (*visit)(Entry &));
    void recursive_postorder(Binary_node<Entry>*sub_root, void (*visit)(Entry &));
    Binary_node<Entry> *root;
    int count;
};

template <class Entry>
Binary_tree<Entry>::Binary_tree(){
    root=NULL;
    count=0;
}
template <class Entry>
bool Binary_tree<Entry>::empty() const {
    return root==NULL;
}
template <class Entry>
void Binary_tree<Entry>::preorder(void (*visit)(Entry &)){
    recursive_preorder(root,visit);
}
template <class Entry>
void Binary_tree<Entry>::recursive_preorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &)) {
    if (sub_root!=NULL){
        (*visit)(sub_root->data);
        recursive_preorder(sub_root->left,visit);
        recursive_preorder(sub_root->right,visit);
    }
}

#endif //BINARY_TREE_BINARY_TREE_H
