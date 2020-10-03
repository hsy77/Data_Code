//
// Created by rain on 2019/10/23.
//

#ifndef SORT_RADIX_SORTING_H
#define SORT_RADIX_SORTING_H

#include "Record.h"
class Radix_Sorting {
public:
    int digit(Record arr[],int n);
    int get_digit(Record x,int d);
    void LSD_radix_sort(Record arr[],int begin,int end,int d);
    void MSD_radix_sort(Record arr[],int begin,int end,int d);
};



#endif //SORT_RADIX_SORTING_H
