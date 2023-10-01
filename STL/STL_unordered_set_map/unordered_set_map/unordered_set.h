#pragma once
#include "HashTable.h"

template<class K, class Hash = HashFunc<K>>
class unordered_set {
public:
    struct SetKeyOfT {
        const K &operator()(const K &key) {
            return key;
        }
    };

public:
    typedef typename HashTable<K, K, SetKeyOfT, Hash>::const_iterator iterator;
    typedef typename HashTable<K, K, SetKeyOfT, Hash>::const_iterator const_iterator;


    iterator begin() {
        return _ht.begin();
    }

    iterator end() {
        return _ht.end();
    }

    const_iterator begin() const {
        return _ht.begin();
    }

    const_iterator end() const {
        return _ht.end();
    }

    //�����pair<iterator,bool>�е�iterator��const���͵ģ���Insert���ص�����ͨ������
    pair<iterator, bool> insert(const K &key) {
        return _ht.Insert(key);
    }

    iterator find(const K &key) {
        return _ht.Find(key);
    }

    bool erase(const K &key) {
        return _ht.Erase(key);
    }

private:
    HashTable<K, K, SetKeyOfT, Hash> _ht;
};