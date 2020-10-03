#include <iostream>
#include "Str_test.h"
int main() {
    int num,index;
    cin>>num;
    Str_test str;
    string target;
    string mys;
    target=str.difference(num);
    cin>>mys;
    index=str.match(target,mys);
    cout<<target;
    cout<<index;
    return 0;
}
//6
//aba
//bc
//aba
//ef
//d
//ef
//aaabc