#include "Trie.hpp"
#include <iostream>
#include <string>
#include <cctype>

Trie::Trie(){
    root = new TrieNode();

}
Trie::Trie(const std::vector<std::string>& v){
    root= new TrieNode();
    for(int i=0; i<v.size(); i++){
        insert(v[i]);
    }
}


void Trie::insert(const std::string& s){
    TrieNode* cur = root;
    for(char c : s){
        //if not letter
        if(!isalpha(c)){
            continue;
        }
        //only consider lowercase
        int i = tolower(c)-'a';
        if(!cur->children[i]){
            cur->children[i]=new TrieNode();
        }
        cur = cur->children[i];
    }
    cur->end_of_word=true;
}

bool Trie::search(const std::string& s) const{
    TrieNode* cur= root;

    for(char c: s){
        int i = tolower(c)-'a';
        if(!cur->children[i]){
            return false;
        }
        cur=cur->children[i];
    }
    return cur->end_of_word;
}


void Trie::print() const{
    std::string word;
    print(root, word);
    //run a loop through kids, if kid is not a nullpointer, look if its end of word if is print it, if not end of word add it to 
    //run code.cpp and the 73rd line will be access code
}

void Trie::print(const TrieNode* node, std::string& word) const{
    if(!node){
        return;
    }
    if(node->end_of_word){
        std::cout<< word<< std::endl;
    }
    for(int i=0; i<ALPHABET_SIZE;i++){
        if(node->children[i]!=nullptr){
            word+=i+'a';
            print(node->children[i], word);
            word.pop_back();
        }
    }
    //Modify print so that it will word #: infront of each word it prints out
    
}