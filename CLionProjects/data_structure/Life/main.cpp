#include <iostream>
#include "Life.h"
using namespace std;
int main() {
    Life life;
    life.initialize();
    life.print();

    cout<<"������y������������or n������ֹͣ��:"<<endl;
    char pre;
    cin>>pre;

//    cout<<pre<<endl;

    while (pre!='n'){
        life.update();
        life.print();
        cout<<"������y������������or n������ֹͣ��:"<<endl;
        cin>>pre;
    }
    return 0;
}