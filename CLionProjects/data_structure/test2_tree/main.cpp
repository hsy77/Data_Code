#include <iostream>
#include <fstream>
#include "Build_tree.h"
#include "split.h"
int main() {
    Build_tree build;
    split_c splitC;
    ifstream in("C:\\Users\\rain\\Desktop\\Dase_DataStructure-master\\1.txt");
    string s;
    char separator=',';
    if(in){
        while(getline(in,s)){
            TreeNode *aroot;
            vector<string> v;
            v=splitC.split(s,separator);
            int index=0;
            build.build_preorder(aroot,v,index);
            build.print(aroot);
            build.max_init(aroot);
            build.max_sum(aroot);
            build.print_max();
        }
    }
    else{
        cout<<"no such file"<<endl;
    }
    return 0;
}
//5 4 2 1 # # 3 # # # # 层次遍历
//6 4 1 # 2 # # 5 # # 8 # 9 # # 先序遍历
//# # # c a # # j i # # # # s p o m 后序遍历