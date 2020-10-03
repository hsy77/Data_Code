//
// Created by rain on 2019/10/23.
//
#include <stdlib.h>
#include <math.h>
#include "Radix_Sorting.h"
const int radix=10;

int Radix_Sorting::digit(Record arr[],int n){
    Record max=arr[0];
    int count=0;
    for (int i=1;i<n;i++){
        if (arr[i]>max) max=arr[i];
    }
    int x=max.the_key();
    while (x>0){
        count++;
        x/=10;
    }
    return count;
}
int Radix_Sorting::get_digit(Record x,int d){
    int key=(x.the_key())/pow(10,d-1);
    return key%10;
}
void Radix_Sorting::LSD_radix_sort(Record arr[],int begin,int end,int d){
    int i,j;
    Record *bucket=(Record *)malloc((end-begin+1)*(sizeof(Record)));//Record *bucket=new Record[end-begin+1];
    for (int k=1;k<=d;k++){
        int count[radix]={0};
        for (i=begin;i<=end;i++)
            count[get_digit(arr[i],k)]++;
        for(i=1;i<radix;i++){
            count[i]=count[i]+count[i-1];
        }
        for(i=end;i>=begin;i--){
            j=get_digit(arr[i],k);
            bucket[count[j]-1]=arr[i];
            count[j]--;
        }
        for (i=begin,j=0;i<=end;i++,j++){
            arr[i]=bucket[j];
        }
    }
    free(bucket);
}

void Radix_Sorting:: MSD_radix_sort(Record arr[],int begin,int end,int d){
    int len =end+1-begin;
    Record **bucket=new Record*[radix];
    for (int i=0;i<radix;i++){
        bucket[i]=new Record[len];
    }
//    Record (*bucket)[5]=new Record[radix][5];
    int count[radix]={0};
    for (int i=begin;i<end+1;i++){
        int j=get_digit(arr[i],d);
        bucket[j][count[j]++]=arr[i];
    }

    for (int i=0;i<count[0];i++){
        arr[begin+i]=bucket[0][i];
    }
    int sum=0;
        for (int j=0;j<radix;j++){
            for (int z=0;z<count[j];z++){
                arr[begin+sum+z]=bucket[j][z];
            }
            sum+=count[j];
        }
        for (int i=0;i<len;i++){
            delete []bucket[i];
        }
        delete[]bucket;

    int p1=begin,p2=p1+count[0]-1;
        for (int i=0;i<radix;i++){
            if (p1<p2&&d>1){
                MSD_radix_sort(arr,p1,p2,d-1);
            }
            if (i<9){
                p1+=count[i];
                p2=p1+count[i+1]-1;
            }
        }
}
