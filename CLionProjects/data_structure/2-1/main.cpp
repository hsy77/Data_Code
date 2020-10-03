#include <iostream>
#include "binary_tree.h"
int main() {
    string s;
    getline(cin,s);
    int target;
    cin>>target;
    binary_tree tree;
    BinaryTreeNode* aroot;
    aroot=tree.build_tree(s);
    tree.search_path(aroot,target);
    if (!tree.flag()){
        cout<<"-1";
    }
    return 0;
}
//10 5 12 4 7 null null