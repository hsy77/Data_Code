//
// Created by rain on 2019/10/18.
//

#ifndef ORDERED_LIST_LIST_H
#define ORDERED_LIST_LIST_H


#include <iostream>
using namespace std;
int const max_list=30;
enum Error_code{underflow,overflow,success,fail,range_error_new, not_present};
template <class list_entry>
class List{
public:
    List();
    int size() const ;
    bool empty() const;
    bool full() const ;
    void clear();
    void traverse(void (*visit)(list_entry &x));
    Error_code retrieve(int position,list_entry &x) const;
    Error_code insert(int position,const list_entry &x);
    Error_code replace(int position,const list_entry &x);
    Error_code remove(int position,list_entry &x);

protected:
    int count_;
    list_entry entry[max_list];
};
template <class list_entry>
List<list_entry>::List() {
    for (int i=0;i<max_list;i++){
        entry[i]=0;
    }
    count_=0;
}

template <class list_entry>
int List<list_entry>::size() const {
    return count_;
}
template <class list_entry>
bool List<list_entry>::empty()const {
    return count_==0;
}
template <class list_entry>
bool List<list_entry>::full()const {
    return count_==max_list;
}
template <class list_entry>
void List<list_entry>::clear(){
    for (int i=0;i<count_;i++){
        entry[i]=0;
    }
    count_=0;
}
//???
template <class list_entry>
void List<list_entry>::traverse(void (*visit)(list_entry &x)){
    for (int i=0;i<count_;i++){
        (*visit)(entry[i]);  //这不是C的风格吗？
    }
}
template <class list_entry>
Error_code List<list_entry>::retrieve(int position,list_entry &x) const {
    if (position<0) return underflow;
    if (position>=count_)
        return range_error_new;
    x=entry[position];
    return success;
}
template <class list_entry>
Error_code List<list_entry>::insert(int position,const list_entry &x){
    if (position<0||position>count_) return range_error_new;
    if (full())
        return overflow;
    for (int i=count_;i>position;i--){
        entry[i]=entry[i-1];
    }
    entry[position]=x;
    count_++;
    return success;
}
template <class list_entry>
Error_code List<list_entry>::replace(int position,const list_entry &x){
    if (position<0) return underflow;
    if (position>=count_)
        return range_error_new;
    entry[position]=x;
    return success;
}
template <class list_entry>
Error_code List<list_entry>::remove(int position,list_entry &x){
    if (position<0) return underflow;
    if (position>=count_)
        return range_error_new;
    for (int i=position;i<count_;i++){
        entry[i]=entry[i+1];
    }
    count_-=1;
    return success;
}

template <class list_entry>
void print(list_entry &x){
    cout<<x;
}


#endif //ORDERED_LIST_LIST_H
