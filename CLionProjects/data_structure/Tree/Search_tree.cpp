//
// Created by rain on 2019/11/13.
//
#include <iostream>
#include "Search_tree.h"
void Search_tree::BuildTree_postorder(TreeNode* &aroot,string &postorder,int &index){
    if (index>=0){
        if (postorder[index]=='#'){
            aroot=NULL;
        }
        else {
            aroot=new TreeNode();
            aroot->data=postorder[index];//放进去的是字符？？yep
            BuildTree_postorder(aroot->rightChild,postorder,--index);
            BuildTree_postorder(aroot->leftChild,postorder,--index);
        }
    }
}

void Search_tree::Search_Node(TreeNode* &aroot,char target){
    if (aroot==NULL){
        cout<<"no tree"<<endl;
    }
    else{
        if (aroot->data==target){
            tree_node_.push(aroot->data);
        }
        else if (aroot->data>target){
            Search_Node(aroot->leftChild,target);
            tree_node_.push(aroot->data);
        }
        else{
            Search_Node(aroot->rightChild,target);
            tree_node_.push(aroot->data);
        }//记得括号
    }
}
void Search_tree::print_route(){
    while (tree_node_.size()>0){
        cout<<tree_node_.top();
        if (tree_node_.size()!=1){
            cout<<"->";
        }
        tree_node_.pop();
    }
}
Error_code Search_tree::search_rem(TreeNode *&aroot, char rm_target) {
    TreeNode* sub_root;
    if (aroot->data==rm_target){
        return Remove_Node(aroot);
    }
    else if (aroot->data>rm_target){
        search_rem(aroot->leftChild,rm_target);
    }
    else search_rem(aroot->rightChild,rm_target);
}

Error_code Search_tree::Remove_Node(TreeNode *&sub_root){
    if (sub_root==NULL){
        return not_present;
    }
    TreeNode* to_delete;
    if (sub_root->leftChild==NULL){
        sub_root=sub_root->rightChild;
    }
    else if (sub_root->rightChild==NULL){
        sub_root=sub_root->leftChild;
    }
    else{//not null
        to_delete=sub_root->leftChild;
        TreeNode* parent=sub_root;
        while (to_delete->rightChild!=NULL){
            parent=to_delete;
            to_delete=to_delete->rightChild;
        }
        sub_root->data=to_delete->data;
        if (parent==sub_root){//分清情况到底是什么
            parent->leftChild=to_delete->leftChild;
        }
        else {
            parent->rightChild=to_delete->leftChild;
        }
    }
    delete to_delete;
}

void Search_tree::inorder(TreeNode* &aroot){
    if (aroot!=NULL){
        inorder(aroot->leftChild);
        cout<<aroot->data;
        inorder(aroot->rightChild);
    }
}
