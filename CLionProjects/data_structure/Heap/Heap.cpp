//
// Created by rain on 2019/11/16.
//
//#include <iostream>
//using namespace std;
#include "Heap.h"
bool operator > (point p1,point p2){
    if (p1.x>p2.x) return true;
    else if (p1.x==p2.x) {
        return p1.y > p2.y;
    }
    else return false;
}

ostream & operator << (ostream & output,point p){
    output<<'<'<<p.x<<','<<p.y<<'>';
}
void Heap::Build_heap(point A[]){
    for (int i=size/2;i>=1;i--){
        Heapify(A,i);
    }
}

void Heap::size_heap(int n) {
    size=n;
}

void Heap::Heapify(point A[], int i) {
    int l=2*i;
    int r=2*i+1;
    int largest=0;
    if (l<=size&&A[l]>A[i]){ //重定向操作符  yep
        largest=l;
    }
    else largest=i;
    if (r<=size&&A[r]>A[largest])
        largest=r;
    if (largest!=i){
        point x;
        x=A[largest];
        A[largest]=A[i];
        A[i]=x;
        Heapify(A,largest);
    }
}

void Heap::Heap_sort(point A[]) {
    Build_heap(A);
    for (int i=size;i>1;i--){
        point x;
        x=A[1];
        A[1]=A[size];
        A[size]=x;
        size-=1;
        Heapify(A,1);
    }
}

void Heap::print(point *A,int n) {
    for (int i=1;i<=n;i++){
        cout<<A[i]<<' ';
    }
    cout<<endl;
}

point Heap::Extra_Max(point A[]) {
    point max=A[1];
    A[1]=A[size];
    size-=1;
    Heapify(A,1);
    return max;
}

void Heap::insert(point *A, point key) {
    A[size]=key;
    Build_heap(A);
}