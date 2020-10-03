//
// Created by rain on 2019/11/1.
//

#ifndef DELETEDUPLICATES_SOLUTION_H
#define DELETEDUPLICATES_SOLUTION_H

#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
        int val;
       ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
class Solution {
public:
    Solution(){
        head_=new ListNode(0);
        head_->next=NULL;
        end_=head_;
    }
    void append(int x){
        ListNode *p=new ListNode(x);
        end_->next=p;
        end_=p;
        end_->next=NULL;
    }
    ListNode * head(){
        return head_;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre;
        ListNode *now;
        if (head->next==NULL){
            return head;
        }
        pre=head->next;
        now=pre->next;
        while (now!=NULL){
            if (pre->val==now->val){
                pre->next=now->next;
                now=pre->next;
            }
            else {
                pre=now;
                now=pre->next;
            }
        }
        return head;
    }
private:
    ListNode* head_;
    ListNode* end_;
};



#endif //DELETEDUPLICATES_SOLUTION_H
