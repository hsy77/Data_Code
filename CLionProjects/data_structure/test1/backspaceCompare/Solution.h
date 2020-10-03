//
// Created by rain on 2019/11/1.
//

#ifndef BACKSPACECOMPARE_SOLUTION_H
#define BACKSPACECOMPARE_SOLUTION_H

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s;
        stack<char> t;
        for (int i=0;i<S.size();i++){
            if (s.size()==0&&S[i]=='#'){

            }
            else if (s.size()>0&&S[i]=='#'){
                s.pop();
            }
            else{
                s.push(S[i]);
            }
        }
        for (int i=0;i<T.size();i++){
            if (t.size()==0&&T[i]=='#'){

            }
            else if (t.size()>0&&T[i]=='#'){
                t.pop();
            }
            else{
                t.push(T[i]);
            }
        }
        if (s.size()!=t.size()){
            return false;
        }
        else {
            while (s.size()>0&&s.top()==t.top()){
                s.pop();
                t.pop();
            }
            if (s.size()>0){
                return false;
            }
            else return true;
        }

    }
};



#endif //BACKSPACECOMPARE_SOLUTION_H
