#include <iostream>
#include "CirQueue.h"
using namespace std;
//是结构体怎么办？
int main() {
    int n;
    struct item{
        int name;
        int number;
    }items;
    CirQueue<struct item> student;
    cout<<"Type n for n students and type the name and numbers."<<endl;
    cin>>n;
    int i;
    while(!student.full()){
        cin>>items.name;
        cin>>items.number;
        student.append(items);
    }
    for (i=10;i<n;i++){
        student.serve_and_retrieve(items);
        cout<<items.name<<" ";
        cout<<items.number<<" ";
        cin>>items.name;
        cin>>items.number;
        student.append(items);
    }

    while(!student.empty()){
        student.serve_and_retrieve(items);
        cout<<items.name<<" ";
        cout<<items.number<<" ";
    }


    return 0;
}