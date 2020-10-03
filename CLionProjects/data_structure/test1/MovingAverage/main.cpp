#include <iostream>
#include "Solution.h"
int main() {
    int size;
    cin>>size;
    MovingAverage m = MovingAverage(size);
    cout<<m.next(11)<<endl;
    cout<<m.next(25)<<endl;
    cout<<m.next(39)<<endl;
    cout<<m.next(66)<<endl;
    cout<<m.next(75)<<endl;
    cout<<m.next(32)<<endl;
    cout<<m.next(77)<<endl;
    return 0;
}