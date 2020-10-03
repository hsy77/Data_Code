#include <iostream>
#include "Solution.h"
using namespace std;
int main() {
    Solution list;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        list.append(x);
    }
    ListNode *l1;
    ListNode *result;
    l1=list.head();
    result=list.deleteDuplicates(l1);
    while (result!=NULL){
    result=result->next;
    cout<<result->val<<" ";
    }
    return 0;
}