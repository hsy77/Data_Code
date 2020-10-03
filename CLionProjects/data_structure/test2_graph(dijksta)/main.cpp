#include <iostream>
#include <fstream>
#include "min_road.h"
int main() {
    min_road min;
    ifstream f("C:\\Users\\rain\\Desktop\\test.txt");
    string s;
    if(f){
        while(getline(f,s)){
            min.graph(s);
        }
    }
    min.Dijksta();
    int len;
    len=min.length();
    cout<<len;
    return 0;
}
