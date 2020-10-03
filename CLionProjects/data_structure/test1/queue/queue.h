//
// Created by rain on 2019/11/1.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <stack>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while (s1.size()>1){
            s2.push(s1.top());
            s1.pop();
        }
        int x=s1.top();
        s1.pop();
        while (s2.size()>0){
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }

    /** Get the front element. */
    int peek() {
        while (s1.size()>0){
            s2.push(s1.top());
            s1.pop();
        }
        int x=s2.top();
        while (s2.size()>0){
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return ((s1.size()+s2.size())==0);
    }

private:
    stack<int> s1;
    stack<int> s2;
};



#endif //QUEUE_QUEUE_H
