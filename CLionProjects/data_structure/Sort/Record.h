//
// Created by rain on 2019/10/24.
//

#ifndef SORT_RECORD_H
#define SORT_RECORD_H


#include <iostream>
using namespace std;

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


#endif //SORT_RECORD_H
