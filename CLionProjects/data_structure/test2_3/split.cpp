//
// Created by rain on 2019/12/13.
//

#include "split.h"
vector<string>  split_c::split(string s,char c){
    vector<string> v;
    string q;
    for (int i=0;i<s.size();i++){
        if (s[i]!=c){
            q.push_back(s[i]);
        }
        else {
            if (s[i-1]==' '){
                continue;
            }
            v.push_back(q);
            q = "";
        }
    }
    v.push_back(q);
    return v;
}