//
// Created by rain on 2019/9/20.
//

#include "CirLinklist.h"
CirLinklist::CirLinklist(){ //构造函数
    head=new Node();
    //head->entry=1;
    head->next=head;
    count=0;
}

void CirLinklist::append(Node_entry n){
    Node *p = new Node();
    p->entry=n;
    p->next = head->next;
    head->next = p;
}
void CirLinklist::create_CirLinklist(int n) {
    CirLinklist();
    int i;
    for (i = n; i >0; i--) {
        append(i);
    }
    count=n;
}

void CirLinklist:: delete_CirLinklist(int m){
    Node *cur,*pre;
    int num=1;
    pre=head;
    cur=head->next;
    while (count>1){
        if (cur==head) {
            pre=cur;
            cur=pre->next;
        }
        if (num==m){
            pre->next=cur->next;
            delete cur;
            cur=NULL;
            cur=pre->next;
            count--;
            num=1;
        }
        else{
            num++;
            pre=cur;
            cur=pre->next;
        }
    }
//    for(cur=head->next;count>1;pre=cur,cur=cur->next){
//        if (cur==head) continue;
//        num++;
//        if(num % m==0){
//            pre->next=cur->next;
//            delete cur;
//            cur=NULL;
//            count--;
//        }
//    }

}

Node_entry CirLinklist::solve(){
    return (head->next)->entry;
}