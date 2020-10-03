#include <iostream>
#include "Search_tree.h"
int main() {
    string postorder;
    Search_tree sort_tree;
    TreeNode* root;
    char target;
    char rm_target;
    cout<<"enter binary sort tree:";
    cin>>postorder;

    int index=postorder.length()-1;
    sort_tree.BuildTree_postorder(root,postorder,index);
    cout<<"target=";
    cin>>target;
    sort_tree.Search_Node(root,target);
    sort_tree.print_route();
    cout<<endl;
    cout<<"delete node:";
    cin>>rm_target;
    sort_tree.search_rem(root,rm_target);
    sort_tree.inorder(root);
    return 0;
}
//###ca##ji####spom