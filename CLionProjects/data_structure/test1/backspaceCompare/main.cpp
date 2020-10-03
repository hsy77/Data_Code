#include <iostream>
#include "Solution.h"
using namespace std;
int main() {
    string S,T;
    bool ret;
    cin>>S;
    cin>>T;
    Solution str;
    ret=str.backspaceCompare(S,T);
    if (ret==1){
        cout<<"true";
    }
    else cout<<"false";
    return 0;
}