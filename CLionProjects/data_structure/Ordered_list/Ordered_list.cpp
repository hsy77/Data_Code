//
// Created by rain on 2019/10/14.
//

#include "Ordered_list.h"
Record::Record(int x, int y) {
    key=x;
    other=y;
}
int Record::the_key() const {
    return key;
}

bool operator<(const Record &x, const Record &y){ //应该写在那边？
    return x.the_key()<y.the_key();
}
bool operator>(const Record &x, const Record &y){
    return x.the_key()>y.the_key();
}
ostream & operator<<(ostream &output,Record &x){
    output<<x.the_key();
    output<<" ";
}

Key::Key(int x) {
    key=x;
}
Key::Key(const Record &r) {
    key=r.the_key();
}
int Key::the_key() const {
    return key;
}
bool operator==(const Key &x, const Key &y){
    return x.the_key()==y.the_key();
}
bool operator<(const Key &x, const Key &y){
    return x.the_key()<y.the_key();
}
bool operator>(const Key &x, const Key &y){
    return x.the_key()>y.the_key();
}


Ordered_list::Ordered_list(){

}
Error_code Ordered_list::insert(const Record &data){
    int s=size();
    int position;
    for (position=0;position<s;position++){
        Record list_data;
        retrieve(position,list_data);
        if (data<list_data) break;
    }
    return List<Record>::insert(position,data);
}
Error_code Ordered_list::insert(int position,const Record &data){
    Record list_data;
    if (position>0){
        retrieve(position-1,list_data);
        if (list_data>data) return fail;
    }
    if (position<count_){
        retrieve(position,list_data);
        if (list_data<data) return fail;
    }
    return List<Record>::insert(position,data);
}
Error_code Ordered_list::replace(int position,const Record &data){
    Record list_data;
    if (position>0){
        retrieve(position-1,list_data);
        if (list_data>data) return fail;
    }
    if (position<count_-1){
        retrieve(position+1,list_data);
        if (list_data<data) return fail;
    }
    return List<Record>::replace(position,data);
}