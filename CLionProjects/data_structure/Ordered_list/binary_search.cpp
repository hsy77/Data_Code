//
// Created by rain on 2019/10/22.
//

#include "binary_search.h"
Error_code binary_search::loop(const Ordered_list &the_list,const Key &target,int &position){
    Record data;
    int count=0;
    int bottom=0,top=the_list.size()-1;
    while (bottom<=top){
        int mid=(bottom+top)/2;
        the_list.retrieve(mid,data);
        if (data==target){
                position=mid;
                cout<<position<<' ';
                position-=1;
                the_list.retrieve(position,data);
                while (data==target && position>=0){
                    cout<<position<<' ';
                    position-=1;
                    the_list.retrieve(position,data);
                }
                position=mid+1;
                the_list.retrieve(position,data);
            while (data==target){
                cout<<position<<' ';
                position+=1;
                the_list.retrieve(position,data);
            }
            return success;
        }
        else if (data<target){
            bottom=mid+1;
        }
        else {
            top=mid-1;
        }
    }
    return not_present;
}

Error_code binary_search::recursion(const Ordered_list &the_list,const Key &target,int bottom,int top,int &position){
    Record data;
    if (bottom<=top){
        int mid=(bottom+top)/2;
        the_list.retrieve(mid,data);
        if (data>target){
            recursion(the_list,target,bottom,mid-1,position);
        }
        else if (data<target){
            recursion(the_list,target,mid+1,top,position);
        }
        else {
            position=mid;
            cout<<position<<' ';
            recursion(the_list,target,bottom,mid-1,position);
            recursion(the_list,target,mid+1,top,position);
        }
    }
    if (position>=0) return success;
    else return not_present;
}