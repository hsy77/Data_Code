//
// Created by rain on 2019/10/27.
//

#ifndef LEECODE_STACKLEE_H
#define LEECODE_STACKLEE_H

#include <stack>
class stacklee {
public:
    int backspaceCompare(string S, string T) {
        stack<char> s;
        stack<char> t;
        for (int i=0;i<S.size();i++){
            if (S[i]=='#'&&s.size()>0){
                s.pop();
            }
            else if (S[i]=='#'&&s.size()==0){

            }
            else {
                s.push(S[i]);
            }
        }
        for (int i=0;i<T.size();i++){
            if (T[i]=='#'&&t.size()!=0){
                t.pop();
            }
            else if (T[i]=='#'&&t.size()==0){

            }
            else {
                t.push(T[i]);
            }
        }
        if (s.size()!=t.size()){
            return 0;
        }
        else{
            while(s.size()>0&&s.top()==t.top()){
                s.pop();
                t.pop();
            }
            if (s.size()!=0){
                return 0;
            }
            else return 1;
        }
    }
};


#endif //LEECODE_STACKLEE_H
