#include "HashMap.hpp"
#include <iostream>


template <typename K, typename V>
HashMap<K, V>::HashMap(int size):n(0){
    data.resize(size, nullptr);

    deleted=new HashNode<K, V>(K(), V());
}



template <typename K, typename V>
bool HashMap<K, V>::empty() const{
    return n==0;
}

template <typename K, typename V>
bool HashMap<K, V>::full() const{
    return n == data.size();
}

template <typename K, typename V>
int HashMap<K, V>::hash(const K& key) const{
    return key % data.size();
}

template <typename K, typename V>
void HashMap<K, V>::insert(const K& key, const V& value){
    if(full()){
        return;
    }

    //Find the hash
    int index=hash(key);

    while(data[index] && data[index]!=deleted){
        index=(index+1)%data.size(); //go to the next position

    }

    // Insert the node
    data[index]=new HashNode<K,V>(key, value);
    n++;


}

template <typename K, typename V>
void HashMap<K, V>::print(){
    for(int i=0; i<data.size(); i++){
        std::cout<< i << " ";
        if(data[i]==nullptr){
            std::cout<< "nullptr\n";
        }
        else if(data[i]==deleted){
            std::cout<< "deleted\n";
        }
        else{
            std::cout<<"{ "<<data[i]->key<< "; "<< data[i]->value<< "} \n";
        }
    }
}



template <typename K, typename V>
int HashMap<K, V>::searchIndex(const K& key) const{
    int index = hash(key); //get index from key
    int startIndex = index;

    // Keep looking until we find a nullptr (end of chain)
    while (data[index] != nullptr) {
        // If it's not a deleted node, check the key
        if (data[index] != deleted) {
            if (data[index]->key == key) {
                return index;
            }
        }
        
        // Move to next index
        index = (index + 1) % data.size();

        // Safety break if the map is full and we've looped back
        if (index == startIndex) break;
    }

    // Key was not found
    return -1;
}


template <typename K, typename V>
const V& HashMap<K, V>::search(const K& key) const{
    int index = searchIndex(key);

    if (index == -1) {
        // Since we must return a reference, and the key doesn't exist,
        // we throw an exception.
        throw std::runtime_error("Key not found in HashMap");
    }

    return data[index]->value;
}


//in class
template <typename K, typename V>
void HashMap<K, V>::remove(const K& key) const{
    int index = hash(key); //get index from key
    int startIndex = index;

    // Keep looking until we find a nullptr (end of chain)
    while (data[index] != nullptr) {
        // If it's not a deleted node, check the key
        if (data[index] != deleted) {
            if (data[index]->key == key) {
                delete data[index];
            }
        }
        
        // Move to next index
        index = (index + 1) % data.size();

        // Safety break if the map is full and we've looped back
        if (index == startIndex) break;
    }

    // Key was not found
    return;
}
