#include <iostream>
#include "CirLinklist.h"
using namespace std;
int main() {
    cout<<"print n people and m out"<<endl;
    CirLinklist cir;
    int n,m;
    cin>>n;
    cir.create_CirLinklist(n);
    cin>>m;
    cir.delete_CirLinklist(m);
    cout<<cir.solve()<<endl;
    return 0;
}