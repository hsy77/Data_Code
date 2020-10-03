//
// Created by rain on 2019/11/16.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

//#include <priority_queue>
#include <iostream>
using namespace std;
const int max=10;
struct point{
    int x;
    int y;
};
bool operator > (point p1,point p2);
ostream & operator << (ostream & output,point p);  //????网上搜索一下
class Heap {
public:
    void Build_heap(point A[]);
    void Heapify(point A[],int i);
    void Heap_sort(point A[]);
    void size_heap(int n);
    void print(point A[],int n);
    point Extra_Max(point *A);
    void insert(point*A,point key);
private:
    int size;
};


#endif //HEAP_HEAP_H
