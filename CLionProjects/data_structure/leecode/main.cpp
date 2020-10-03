#include <vector>
using namespace std;
#include <iostream>
//#include "leecode.h"
//#include "stacklee.h"
#include <string>
int main() {
    int **x=new int*[10];
    for (int i=0;i<10;i++){
        x[i]=new int[10];
    }
    x[0][5]=0;
    int *y=new int[10*10];
    y[5]=0;
    int (*z)[10]=new int[10][10];
    z[0][5]=0;
    for (int i=0;i<10;i++){
        delete[] x[i];
    }
    delete[] x;
    delete[] y;
    delete[] z;
    return 0;
}