#include <iostream>
#include "Skiing.h"
using namespace std;
int main() {
    cout<<"print the row and the col "
           "and with row*col h(0<=h<=10000)"<<endl;
    int row,col;
    Skiing ski;
    cin>>row;
    cin>>col;
    ski.init_matrix(row,col);
    ski.BFS_maxlength();
    //ski.DFS_maxlength();
    return 0;
}
//5 5
//1 2 3 4 5
//16 17 18 19 6
//15 24 25 20 7
//14 23 22 21 8
//13 12 11 10 9 max=24

//4 3
//24 20 15
//20 24 25
//24 20 20
//13 24 19 max=3

//3 3
//24 20 15
//20 24 25
//24 20 20 max=3

//3 3
//20 24 25
//24 20 20
//13 24 19