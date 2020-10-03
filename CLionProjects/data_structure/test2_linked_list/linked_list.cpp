//
// Created by rain on 2019/12/12.
//

#include "linked_list.h"
linked_list::linked_list(){ //构造函数
    head_=new ListNode();
    head_->val=0;
    head_->next=NULL;
    end_=head_;
}

void linked_list::init(){
    head2_=new ListNode();
    head2_->val=0;
    head2_->next=NULL;
    end2_=head2_;
}


void linked_list::in_list(string s) {
    vector<string> v;
    v=splitC.split(s,separator);
    int num=v.size();
    for (int i=0;i<num;i++){
        int n=stoi(v[i]);
        insert(n);
    }
}

void linked_list::print(ListNode* head) {
    ListNode * pre;
    pre=head;
    while(pre){
        cout<<pre->val<<' ';
        pre=pre->next;
    }
    cout<<endl;
}

void linked_list::insert(int n) {
    ListNode * p=new ListNode();
    p->val=n;
    if (head_->next==NULL){
        end_->next=p;
        p->next=NULL;
        end_=p;
    }
    else {
        ListNode* pre=head_;
        ListNode* cur=pre->next;
        for (pre;pre->next!=NULL;pre=cur){
            cur=pre->next;
            if (n<=cur->val){
                p->next=cur;
                pre->next=p;
                break;
            }
        }
        if (pre->next==NULL){
            end_->next=p;
            p->next=NULL;
            end_=p;
        }
    }
}

void linked_list::in_list1(string s) {
    init();
    vector<string> v;
    v=splitC.split(s,separator);
    int num=v.size();
    for (int i=0;i<num;i++){
        int n=stoi(v[i]);
        insert1(n);
    }
}
void linked_list::insert1(int n) {
    ListNode * p=new ListNode();
    p->val=n;
    if (head2_->next==NULL){
        end2_->next=p;
        p->next=NULL;
        end2_=p;
    }
    else {
        ListNode* pre=head2_;
        ListNode* cur=pre->next;
        for (pre;pre->next!=NULL;pre=cur){
            cur=pre->next;
            if (n<=cur->val){
                p->next=cur;
                pre->next=p;
                break;
            }
        }
        if (pre->next==NULL){
            end2_->next=p;
            p->next=NULL;
            end2_=p;
        }
    }
}

ListNode* linked_list::merge() {
    ListNode* l1=head_->next;
    ListNode* l2=head2_->next;
    ListNode *l;
    ListNode *now;
    if (l1==NULL){
        return l2;
    }
    if (l2==NULL){
        return l1;
    }
    if ((l1->val)<(l2->val)){
        l=l1;
        l1=l1->next;
    }
    else{
        l=l2;
        l2=l2->next;
    }
    now=l;
    while (l1!=NULL&&l2!=NULL){
        if ((l1->val)<(l2->val)){
            now->next=l1;
            now=l1;
            l1=l1->next;
        }
        else{
            now->next=l2;
            now=l2;
            l2=l2->next;
        }
    }
    if (l1==NULL&&l2!=NULL){
        now->next=l2;
        now=l2;
    }
    else if (l2==NULL&&l1!=NULL){
        now->next=l1;
        now=l1;
    }
    return l;
}