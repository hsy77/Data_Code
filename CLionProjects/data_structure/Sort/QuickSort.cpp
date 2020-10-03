//
// Created by rain on 2019/11/4.
//

#include "QuickSort.h"
void QuickSort::qksort(Record arr[],int t,int w){
    if (t>=w) return;
    int i=t,j=w;
    Record x=arr[t];
    while (i<j){
        while (i<j&&arr[j]>x){
            j--;
        }
        if (i<j){
            arr[i]=arr[j];
            i++;
        }
        while (i<j&&arr[i]<x){
            i++;
        }
        if (i<j){
            arr[j]=arr[i];
            j--;
        }
    }
    arr[j]=x;
    qksort(arr,t,j-1);
    qksort(arr,j+1,w);
}