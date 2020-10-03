//
// Created by rain on 2019/12/5.
//

#include "binary_tree.h"
BinaryTreeNode::BinaryTreeNode() {
    m_nValue=0;
    m_pRight=NULL;
    m_pLeft=NULL;
}
BinaryTreeNode* binary_tree::build_tree(string &s){
    queue<BinaryTreeNode*> q;
    int index=0;
    string x;
    while (index<=s.length()&&s[index]!=' '){
        x.push_back(s[index]);
        index+=1;
    }
    BinaryTreeNode* aroot=new BinaryTreeNode();
    aroot->m_nValue=stoi(x);
    q.push(aroot);
    while (index<s.length()&&!q.empty()){
        index+=1;
        x = "";
        while (index<=s.length()&&s[index]!=' ') {
                x.push_back(s[index]);
                index += 1;
            }
        if (x=="null"){
            q.front()->m_pLeft=NULL;
        }
        else {
            BinaryTreeNode* left=new BinaryTreeNode();
            left->m_nValue=stoi(x);
            q.front()->m_pLeft=left;
            q.push(left);
        }
        index+=1;
        x = "";
        while (index<s.length()&&s[index]!=' ') {
            x.push_back(s[index]);
            index += 1;
        }
        if (x=="null"){
            q.front()->m_pRight=NULL;
        }
        else {
            BinaryTreeNode* right=new BinaryTreeNode();
            right->m_nValue=stoi(x);
            q.front()->m_pRight=right;
            q.push(right);
        }
        q.pop();
    }
    return aroot;
}

void binary_tree::search_path(BinaryTreeNode *aroot, int target) {
    int value=aroot->m_nValue;
    q_data.push_back(value);
    if (aroot->m_pLeft==NULL && aroot->m_pRight==NULL && value==target){
        flag_=true;
        cout<<'[';
        for (int i=0;i<q_data.size();i++){
            cout<<q_data[i];
            if (i!=q_data.size()-1){
                cout<<',';
            }
        }
        cout<<']';
        return;
    }
    if (aroot->m_pLeft==NULL && aroot->m_pRight==NULL && value!=target){
        return;
    }
    else {
        search_path(aroot->m_pLeft,target-value);
        q_data.pop_back();
        search_path(aroot->m_pRight,target-value);
        q_data.pop_back();
    }
    return;
}

bool binary_tree::flag() {
    return flag_ ;
}