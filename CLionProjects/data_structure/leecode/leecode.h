//
// Created by rain on 2019/10/26.
//

#ifndef LEECODE_LEECODE_H
#define LEECODE_LEECODE_H
#include <stack>
#include <queue>
struct ListNode {
        int val;
        ListNode *next;
    };
class Solution {
public:
    Solution(){ //构造函数
        head_=new ListNode();
        head_->val=1;
        head_->next=NULL;
    }
    void append(int n){
        Solution();
        ListNode *p=new ListNode();
        p->val=n;
        p->next = head_->next;
        head_->next = p;
    }
    void init(){
        head2_=new ListNode();
        head2_->val=3;
        head2_->next=NULL;
    }
    void append2(int n){
        ListNode *p=new ListNode();
        p->val=n;
        p->next = head2_->next;
        head2_->next = p;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * l1;
        ListNode * l2;
        l1=headA;
        l2=headB;
        int size1=0;
        int size2=0;
        wh (l1){
            size1++;
            l1=l1->next;
        }
        if (l2){
            size2++;
            l2=l2->next;
        }
        l1=headA;
        l2=headB;
         if (size1>size2){
             int sub=size1-size2;
             while (sub>0){
             l1=l1->next;
                 sub--;
         }
         }
        if (size1<size2){
            int sub=size2-size1;
            while (sub>0){
                l2=l2->next;
                sub--;
            }
        }
        // while (l1!=NULL&&l1!=l2){
        //     l1=l1->next;
        //     l2=l2->next;
        // }
        // if (l1==NULL){
        //     return NULL;
        // }
        // else return l1;
        return l2;
    }

    ListNode* _head(){
        return head_;
    }
    ListNode* _head2(){
        return head2_;
    }
private:
    ListNode* head_;
    ListNode* head2_;
    ListNode* l;
    ListNode* end;
};


#endif //LEECODE_LEECODE_H
