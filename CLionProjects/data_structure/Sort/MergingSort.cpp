//
// Created by rain on 2019/11/4.
//

#include "MergingSort.h"

void MergingSort::sort(Record arr[],int left,int right){
    Record *temp=new Record[right+1-left];
    if (left<right){
        int mid=(left+right)/2;
        sort(arr,left,mid);
        sort(arr,mid+1,right);
        merge(arr,left,mid,right,temp);
    }
}
void MergingSort::merge(Record arr[],int left,int mid,int right,Record temp[]){
    int i=left;
    int j=mid+1;
    int t=0;
    while (i<=mid&&j<=right){
         if (arr[i]<arr[j]){
             temp[t++]=arr[i++];
         }
         else {
             temp[t++]=arr[j++];
         }
    }
    while (i<=mid){
        temp[t++]=arr[i++];
    }
    while (j<=right){
        temp[t++]=arr[j++];
    }
    t=0;
    for (int i=left;i<=right;i++){
        arr[i]=temp[t++];
    }
}