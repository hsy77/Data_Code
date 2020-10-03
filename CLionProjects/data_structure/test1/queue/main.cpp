#include <iostream>
#include "queue.h"
int main() {
    MyQueue queue;
    queue.push(1);
    queue.push(1);
    queue.push(3);
    cout<<queue.pop()<<endl;
    cout<<queue.peek()<<endl;  // 返回 1
    cout<<queue.pop()<<endl;   // 返回 1
    cout<<queue.peek()<<endl;
    cout<<queue.empty()<<endl; // 返回 false
    cout<<queue.pop()<<endl;
    cout<<queue.empty();
    return 0;
}