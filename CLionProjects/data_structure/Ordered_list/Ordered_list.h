//
// Created by rain on 2019/10/14.
//
#include <iostream>
#include "List.h"
using namespace std;
#ifndef ORDERED_LIST_ORDERED_LIST_H
#define ORDERED_LIST_ORDERED_LIST_H


class Record{
public:
    Record(int x=0,int y=0);//没有写的话似乎无法取对象
    int the_key() const;

private:
    int key;
    int other;
};
bool operator<(const Record &x, const Record &y);
bool operator>(const Record &x, const Record &y);
ostream & operator<<(ostream &output,Record &x);

class Key{
    int key;
public:
    Key(int x=0);
    Key(const Record &r);
    int the_key() const;
};
bool operator==(const Key &x, const Key &y); //为什么没有friend？
bool operator<(const Key &x, const Key &y);
bool operator>(const Key &x, const Key &y);


class Ordered_list:public List<Record>{
public:
        Ordered_list();
        Error_code insert(const Record &data);
        Error_code insert(int position,const Record &data);
        Error_code replace(int position,const Record &data);

};



#endif //ORDERED_LIST_ORDERED_LIST_H
