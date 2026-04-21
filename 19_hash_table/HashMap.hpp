#ifndef HASHMAP_HPP
#define HASHMAP_HPP
#include "HashNode.hpp"
#include <vector>

template <typename K, typename V>
class HashMap{
    public:
        HashMap(int size=31);

        bool empty() const;
        bool full() const;

        void insert(const K& key, const V& value);
        void print();
        const V& search(const K& key) const;
        void remove(const K& key) const;

        


    private:
        // vector data of type 
        std::vector<HashNode<K, V>*> data;
        int n; //the number of records in the table

        HashNode<K, V>* deleted;

        int hash(const K& key) const;

        int searchIndex(const K& key) const;

        

        

};

#include "HashMap.tpp"




#endif