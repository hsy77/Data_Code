//
// Created by rain on 2019/10/22.
//

#ifndef ORDERED_LIST_BINARY_SEARCH_H
#define ORDERED_LIST_BINARY_SEARCH_H

#include "Ordered_list.h"

class binary_search {
public:
    Error_code loop(const Ordered_list &the_list,const Key &target,int &position);
    Error_code recursion(const Ordered_list &the_list,const Key &target,int bottom,int top,int &position);

};


#endif //ORDERED_LIST_BINARY_SEARCH_H
