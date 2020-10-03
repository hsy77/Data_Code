//
// Created by rain on 2019/11/4.
//

#ifndef SORT_MERGINGSORT_H
#define SORT_MERGINGSORT_H

#include "Record.h"
class MergingSort {
public:
    void sort(Record arr[],int left,int right);
    void merge(Record arr[],int left,int mid,int right,Record temp[]);
};


#endif //SORT_MERGINGSORT_H
