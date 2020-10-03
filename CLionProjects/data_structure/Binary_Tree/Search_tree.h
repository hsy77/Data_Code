//
// Created by rain on 2019/11/15.
//

#ifndef BINARY_TREE_SEARCH_TREE_H
#define BINARY_TREE_SEARCH_TREE_H

#include "Binary_tree.h"
enum Error_code{success,not_present,duplicate_error};
template <class Record>
class Search_tree: public Binary_tree<Record> {
public:
    Error_code insert(const Record& new_data);
    Error_code remove(const Record& target);
    Error_code tree_search(Record &target) const;

private:
    Error_code search_and_insert(Binary_node<Record>*&sub_root, const Record &new_data);
    Error_code remove_root(Binary_node<Record>*&sub_root);
    Error_code search_and_destroy(Binary_node<Record>*&sub_root,)
};
template <class Record>
Error_code Search_tree<Record>::tree_search(Record &target) const {
    count+=1;

}
template <class Record>
Error_code Search_tree<Record>::insert(const Record &new_data) {
    Error_code result=search_and_insert(root,new_data);
    if (result==success) count++;
    return result;
}
template <class Record>
Error_code Search_tree::search_and_insert(Binary_node<Record> *&sub_root, const Record &new_data) {
    if (sub_root==NULL){
        sub_root=new Binary_node<Record>(new_data);
    }
    else if (new_data<sub_root->data){
        return search_and_insert(sub_root->left,new_data)
    }
    else if (new_data>sub_root->data){
        return search_and_insert(sub_root->right,new_data)
    }
    else return duplicate_error;
}
template <class Record>
Error_code Search_tree::remove(const Record &target) {

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
#endif //BINARY_TREE_SEARCH_TREE_H
