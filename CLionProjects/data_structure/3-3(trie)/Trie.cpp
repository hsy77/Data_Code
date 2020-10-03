//
// Created by rain on 2019/12/8.
//

#include "Trie.h"
Trie_node::Trie_node() {
    data="";
    for (int i=0;i<num_chars;i++){
        branch[i]=NULL;
    }
    count=0;
}
int Trie::alphabetic_order(char s) {
    if (s==' ') return 0;
    if ('a'<=s<='z') return s-'a'+1;
    if ('A'<=s<='Z') return s-'A'+1;
    return 27;
}
char Trie::key_letter(int position){
    return char(position+96);
}
Trie::Trie() {
    root=NULL;
}

Error_code Trie::insert(type &new_entry) {
    Error_code result=success;
    if (root==NULL) {
        root = new Trie_node;
    }
        int position=0;
        Trie_node* location=root;
        while(location!=NULL&&position<new_entry.length()){
            int next_position=alphabetic_order(new_entry[position]);
            if (location->branch[next_position]==NULL){
                location->branch[next_position]=new Trie_node;
            }
            location->count++;
            location=location->branch[next_position];
            position++;
        }
        if (location->data!="")
            result=duplicate_error;
        else{
            location->data=new_entry;
        }
        return result;
}

Error_code Trie::trie_search(type &target,type &x){
    int position=0;
    Trie_node* location=root;
    while(location!=NULL&&position<target.length()){
        location=location->branch[alphabetic_order(target[position])];
        position++;
    }
    if (location!=NULL&&location->data!=""){
        x=location->data;
        return success;
    }
    else {
        return not_present;
    }
}

void Trie::type_ahead(Trie_node *node, int m) {
    for (int i=1;i<=26;i++){
        if (node->branch[i]!=NULL){
            str_.push_back(key_letter(i));
            if (m==0){
                if (node->branch[i]->count > point.count){
                    point.count=node->branch[i]->count;
                    point.str=str_;
                }
            }
            else{
                type_ahead(node->branch[i],m-1);
            }
            str_.pop_back();
        }
    }
    return;
}

string Trie::ahead_s(int m) {
    type_ahead(root,m-1);
    return point.str;
}