#include <iostream>
#include "Life.h"
using namespace std;
int main() {
    Life life;
    life.initialize();
    life.print();

    cout<<"ÇëÊäÈëy£¨¼ÌÐøµü´ú£©or n£¨³ÌÐòÍ£Ö¹£©:"<<endl;
    char pre;
    cin>>pre;

//    cout<<pre<<endl;

    while (pre!='n'){
        life.update();
        life.print();
        cout<<"ÇëÊäÈëy£¨¼ÌÐøµü´ú£©or n£¨³ÌÐòÍ£Ö¹£©:"<<endl;
        cin>>pre;
    }
    return 0;
}