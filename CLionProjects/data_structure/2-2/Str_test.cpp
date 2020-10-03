//
// Created by rain on 2019/12/6.
//
#include <iostream>
#include "Str_test.h"
string Str_test::difference(int num) {
    string x;
    vector<string> array;
    for (int i=0;i<num;i++){
        cin>>x;
        array.push_back(x);
    }
    int i,j,z;
    for (i=0;i<num-1;i++){
        for (j=i+1;j<num;j++){
            if (array[i]==array[j]){
                break;
            }
        }
        if (j==num) return array[i];
    }
    for (z=0;z<num-1;z++){
        if (array[num-1]==array[z]){
            return "-1";
        }
    }
    if (z==num-1) return array[num-1];
}

int Str_test::match(string target, string mys) {
    string search;
    if (target.length()>mys.length()) return -1;
    else{
        int len=target.length();
        int i;
        for (i=0;i+len<=mys.length();i++){
            search="";
            for (int j=i;j<i+len;j++){
                search.push_back(mys[j]);
            }
            if (target==search){
                return i;
            }
        }
        if ((i+len)==mys.length()){
            return -1;
        }
    }
}