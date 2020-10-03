#include <iostream>
#include "Radix_Sorting.h"
#include "QuickSort.h"
#include "MergingSort.h"
using namespace std;
int main() {
    Radix_Sorting radix;
    QuickSort qsort;
    MergingSort msort;
    cout<<"enter n number:n=";
    int n,x,begin,end,d;
    cin>>n;
    Record arr[n];
    cout<<"please enter n numbers"<<endl;
    for (int i=0;i<n;i++){
        cin>>x;
        arr[i]=Record(x);
    }
    begin=0;
    end=n-1;
    d=radix.digit(arr,n);
//    cout<<"the past=";
//    for (int i=begin;i<=end;i++){
//        cout<<arr[i]<<" ";
//    }
//    cout<<endl;

/*基数排序*/
//    radix.LSD_radix_sort(arr,begin,end,d);
    radix.MSD_radix_sort(arr,begin,end,d);

/*快排*/
//    qsort.qksort(arr,begin,end);

/*归并排序*/
//    msort.sort(arr,begin,end);

    cout<<"after radix sort=";
    for (int i=begin;i<=end;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
//12 34 23 56 234
//36 5 16 98 47 32 36 48 10 95
//45 23 1 678 443 23 11 234