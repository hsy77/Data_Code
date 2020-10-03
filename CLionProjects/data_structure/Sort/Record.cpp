//
// Created by rain on 2019/10/24.
//

#include "Record.h"
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