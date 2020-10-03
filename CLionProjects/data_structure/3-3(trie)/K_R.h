//
// Created by rain on 2019/12/8.
//

#ifndef INC_3_3_K_R_H
#define INC_3_3_K_R_H

#include <string.h>
const int key_size=10;
class Key {
    char str[key_size];
public:
    Key(char s[]);
    char* the_key();
    char key_letter(int position);
};


#endif //INC_3_3_K_R_H
