//
// Created by rain on 2019/12/8.
//

#ifndef INC_3_3_TRIE_H
#define INC_3_3_TRIE_H

#include <string>
#include <vector>
using namespace std;
struct ahead{
    string str;
    int count;
};
const int num_chars=28;
typedef string type;
struct Trie_node{
    type data;
    Trie_node *branch[num_chars];
    Trie_node();
    int count; //记录有多少个str
};
enum Error_code{not_present,success,overflow,underflow,duplicate_error};
class Trie {
public:
    Error_code insert(type &new_entry);
    Error_code trie_search(type &target,type &x);
    Trie();
    int alphabetic_order(char s);
    void type_ahead(Trie_node* node,int m);
    char key_letter(int position);
    string ahead_s(int m);
private:
    Trie_node* root;
    string str_;
    ahead point={"",0};
};


#endif //INC_3_3_TRIE_H
