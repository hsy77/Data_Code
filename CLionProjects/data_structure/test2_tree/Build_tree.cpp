//
// Created by rain on 2019/12/5.
//

#include "Build_tree.h"
TreeNode::TreeNode() {
    left=NULL;
    right=NULL;
}
TreeNode::TreeNode(type &x) {
    data=x;
    left=NULL;
    right=NULL;
}

void Build_tree::build_preorder(TreeNode* &aroot,vector<string> &preorder,int &index){
    if (index<preorder.size()){
        if (preorder[index]=="#"){
            aroot=NULL;
        }
        else {
            aroot=new TreeNode;
            aroot->data=stoi(preorder[index]);
            build_preorder(aroot->left,preorder,++index);
            build_preorder(aroot->right,preorder,++index);
        }
    }
}

//void Build_tree::build_postorder(TreeNode* &aroot,vector<string> &postorder,int &index) {
//    if (index >= 0) {
//        if (postorder[index] == "#") {
//            aroot = NULL;
//        }
//        else {
//            aroot = new TreeNode();
//            aroot->data = postorder[index];//放进去的是字符？？yep
//            build_postorder(aroot->right, postorder, --index);
//            build_postorder(aroot->left, postorder, --index);
//        }
//    }
//}
//
//void Build_tree::build_PreMidorder(TreeNode *&aroot, vector<string> &preorder, vector<string> &midorder, int &index, int pstart, int pend) {
//    int sep=pend;
//    for (int z=pend;z>=pstart;z--){
//        if (!midorder[z].compare(preorder[index])){
//            sep=z;
//            break;
//        }
//    }
//    aroot=new TreeNode;
//    aroot->data=preorder[index];
//    if (sep-1>=pstart){
//        build_PreMidorder(aroot->left, preorder, midorder, ++index, pstart, sep-1);
//    }
//    if (sep+1>=pend){
//        build_PreMidorder(aroot->right, preorder, midorder, ++index, sep+1, pend);
//    }
//    return;
//}
//
//TreeNode* Build_tree::BFS_build(vector<string> &bfsorder) {
//    TreeNode* aroot=new TreeNode(bfsorder[0]);
//    q.push(aroot);
//    int index=1;
//    while (!q.empty()){
//        type x=bfsorder[index];
//        if (x=="#"){
//            q.front()->left=NULL;
//        }
//        else{
//            TreeNode* left=new TreeNode(x);
//            q.front()->left=left;
//            q.push(left);
//        }
//        index=index+1;
//        type y=bfsorder[index];
//        if (y=="#"){
//            q.front()->right=NULL;
//        }
//        else{
//            TreeNode* right=new TreeNode(y);
//            q.front()->right=right;
//            q.push(right);
//        }
//        q.pop();
//        index++;
//    }
//    return aroot;
//}

void Build_tree::recursive_inorder(TreeNode* sub_root){
    if(sub_root){
        recursive_inorder(sub_root->left);
        cout<<sub_root->data<<' ';
        recursive_inorder(sub_root->right);
    }
}
void Build_tree::print(TreeNode* aroot){
    recursive_inorder(aroot);
    cout<<endl;
}
void Build_tree::max_init(TreeNode* aroot){
    TreeNode* node=aroot;
    max=aroot->data;
    while (node->left){
        node=node->left;
        max+=node->data;
    }
}
void Build_tree::max_sum(TreeNode *aroot) {
    if (aroot==NULL){
        int sum=0;
        for (int i=0;i<v.size();i++){
            sum+=v[i];
        }
        if (sum>max) max=sum;
        return;
    }
    else {
        v.push_back(aroot->data);
        max_sum(aroot->left);
        max_sum(aroot->right);
        v.pop_back();
    }
}
void Build_tree::print_max() {
    cout<<max;
}