#include <iostream>
#include "binary_search.h"
using namespace std;
int main() {
    Key target(0);
    Ordered_list my_list;
    for (int i=0;i<10;i++){
        my_list.insert(Record(i,10));//为什么可以只写x？
    }
    my_list.insert(Record(5));
    cout<<"the ordered list is:"<<endl;
    my_list.traverse(print);
    cout<<endl;
    cout<<"the target is:"<<target.the_key()<<endl;
    int bottom=0;
    int top=my_list.size()-1;
    int position=-1;
    //二分查找
    binary_search search;
//    cout<<"using recursion method"<<endl;
//    if (search.recursion(my_list,target,bottom,top,position)==success){
//        cout<<"index= ";
//        search.recursion(my_list,target,bottom,top,position);
//    }
//    else cout<<"no present"<<endl;
    cout<<"using loop method"<<endl;
    cout<<"index= ";
    if (search.loop(my_list,target,position)==success){
    }
    else cout<<"no present"<<endl;
    return 0;
}