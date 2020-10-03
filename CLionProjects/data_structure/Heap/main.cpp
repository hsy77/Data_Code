#include <iostream>
#include <cstring>
#include "Heap.h"
int main() {
    Heap heap;
//    第一题 排序
//    int n;
//    cout<<"how many numbers do you want to enter:";
//    cin>>n;
//    point A[n+1];
//    for (int i=1;i<=n;i++){
//        cin>>A[i].x;
//        cin>>A[i].y;
//    }
//    heap.size_heap(n);
//    heap.Heap_sort(A);
//    heap.print(A,n);

    //第二题 最小k项
    cout<<"print k(display min k items):";
    int k;
    cin>>k;
    point A[k+2];
    cout<<"enter q(quit) if you want to quit"<<endl;
    string c;
    cin>>c;
    int i=0;
    while (c!="q"){
        point p;
        p.x=stoi(c);
        cin>>p.y;
        i+=1;
        if(i<=k){
            A[i]=p;
            cout<<"min "<<k<<" terms:";
            heap.print(A,i);
        }
        else {
            if (p>A[1]){
                cout<<"min "<<k<<" terms:";
                heap.print(A,k);
            }
            else{
                A[1]=p;
                heap.Heapify(A,1);
                cout<<"min "<<k<<" terms:";
                heap.print(A,k);
            }

//            heap.size_heap(i);
//            heap.insert(A,p);
//            heap.Extra_Max(A);
//            cout<<"min "<<k<<" terms:";
//            heap.print(A,k);
            i-=1;
        }
        cin>>c;
    }
    return 0;
}
//1 2 1 1 3 2 3 2