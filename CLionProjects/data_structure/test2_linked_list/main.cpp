#include <iostream>
#include <fstream>
#include "linked_list.h"
int main() {
    linked_list list;
    ifstream in("C:\\Users\\rain\\Desktop\\Dase_DataStructure-master\\2.2.txt");
    string s;
    int index=1;
    if(in){
        while(getline(in,s)){
            if (index==1){
                index++;
                list.in_list(s);
            }
            else {
                list.in_list1(s);
            }
        }
        ListNode* l=list.merge();
        list.print(l);
    }
    else{
        cout<<"no such file"<<endl;
    }
    return 0;
}