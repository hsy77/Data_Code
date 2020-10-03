//
// Created by rain on 2019/12/12.
//

#ifndef UNTITLED_LINKED_LIST_H
#define UNTITLED_LINKED_LIST_H


#include <iostream>
#include "split.h"
struct ListNode {
    int val;
    ListNode *next;
};

class linked_list {
public:
    linked_list(); //构造函数
    void init();
    void in_list(string s);
    void in_list1(string s);
    void print(ListNode* head);
    void insert(int n);
    void insert1(int n);
    ListNode* merge();
private:
    split_c splitC;
    ListNode* head_;
    ListNode* head2_;
    ListNode* end_;
    ListNode* end2_;
    char separator=' ';
};


#endif //UNTITLED_LINKED_LIST_H
