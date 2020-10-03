#include <iostream>
#include <fstream>
#include <string>
#include "Trie.h"
int main() {
    Trie trie;
    int n,m;
    cin>>n;
    cin>>m;
    string s;
    for (int i=0;i<n;i++){
        cin>>s;
        trie.insert(s);
    }
    s=trie.ahead_s(m);
    cout<<s;
    return 0;
}
//3 2
//abc
//abd
//acd
