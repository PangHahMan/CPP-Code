#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

template<class K>
struct HashFunc {
    size_t operator()(const K &key) {
        return key;
    }
};

// �ػ�ģ�壬��string�Ļ����������
template<>
struct HashFunc<string> {
    size_t operator()(const string &s) {
        size_t hash = 0;
        for (auto ch: s) {
            hash += ch;
            hash *= 31;
        }
        return hash;
    }
};

template<class T>
struct HashNode {
    HashNode<T> *_next;
    T _data;

    HashNode(const T &data)
        : _data(data), _next(nullptr) {}
};


//ǰ������
template<class K, class T, class KeyOft, class Hash = HashFunc<K>>
class HashTable;

template<class K, class T, class Ref, class Ptr, class KeyOft, class Hash>
struct HashIterator {
    typedef HashNode<T> Node;
    typedef HashTable<K, T, KeyOft, Hash> HT;
    //Ref��Ptr������T&��T*��Ҳ������const T&/const T*����Ҫ����һ��֧����ͨת��Ϊconst�ĵ�����
    typedef HashIterator<K, T, Ref, Ptr, KeyOft, Hash> Self;
    typedef HashIterator<K, T, T &, T *, KeyOft, Hash> iterator;//����һ��֧��const�ĵ�����

    HashIterator(Node *node, HT *ht)
        : _node(node), _ht(ht) {}

    //֧�ֵ�����
    HashIterator(const iterator &it)
        : _node(it._node), _ht(it._ht) {}

    Ref operator*() {
        return _node->_data;
    }

    Ptr operator->() {
        return &_node->_data;
    }

    bool operator!=(const Self &s) {
        return _node != s._node;
    }

    bool operator==(const Self &s) {
        return _node == s._node;
    }

    Self &operator++() {
        if (_node->_next != nullptr) {
            _node = _node->_next;
        } else {
            //����һ����Ϊ�յ�Ͱ
            KeyOft kot;
            Hash hash;
            // ����ҵ�ǰ��Ͱλ��
            size_t hashi = hash(kot(_node->_data)) % _ht->_tables.size();
            ++hashi;
            while (hashi < _ht->_tables.size()) {
                if (_ht->_tables[hashi] != nullptr) {
                    _node = _ht->_tables[hashi];
                    break;
                } else {
                    ++hashi;
                }
            }

            //û���ҵ��Ļ�������_nodeΪ��
            if (hashi == _ht->_tables.size()) {
                _node = nullptr;
            }
            return *this;
        }
        return *this;
    }
    Node *_node;//������ָ��
    HT *_ht;    //��ϣ�����ڶ�λ��һ��Ͱ
};

template<class K, class T, class KeyOft, class Hash>// Hash���ڽ�keyת���ɿ���ȡģ������
class HashTable {
public:
    typedef HashNode<T> Node;
    typedef HashIterator<K, T, T &, T *, KeyOft, Hash> iterator;
    typedef HashIterator<K, T, const T &, const T *, KeyOft, Hash> const_iterator;

    template<class K1, class T1, class Ref1, class Ptr1, class KeyOft1, class Hash1>
    friend struct HashIterator;//���ڵ���������HashTable�е�private��Ա��������_tables


public:
    ~HashTable() {
        for (auto &cur: this->_tables) {
            while (cur) {
                Node *next = cur->_next;
                delete cur;
                cur = next;
            }
            cur = nullptr;
        }
    }

    iterator begin() {
        Node *cur = nullptr;
        for (size_t i = 0; i < _tables.size(); i++) {
            cur = _tables[i];
            if (cur != nullptr) {
                break;
            }
        }
        return iterator(cur, this);
    }

    iterator end() {
        return iterator(nullptr, this);
    }

    const_iterator begin() const {
        Node *cur = nullptr;
        for (size_t i = 0; i < _tables.size(); i++) {
            cur = _tables[i];
            if (cur != nullptr) {
                break;
            }
        }
        return const_iterator(cur, this);
    }

    const_iterator end() const {
        return const_iterator(nullptr, this);
    }

    //����KeyҲ��K����
    iterator Find(const K &key) {
        if (this->_tables.size() == 0) {
            return iterator(nullptr, this);
        }

        KeyOft kot;//ģ�����������������kv������v���ϲ�map��set��ģ���������(ͨ���º���ʵ��)
        Hash hash;
        size_t hashi = hash(key) % this->_tables.size();
        Node *cur = this->_tables[hashi];
        while (cur) {
            if (kot(cur->_data) == key) {
                return iterator(cur, this);
            }
            cur = cur->_next;
        }
        return iterator(nullptr, this);
    }

    //ɾ����ֵkeyΪK����
    bool Erase(const K &key) {
        Hash hash;
        KeyOft kot;
        size_t hashi = hash(key) % this->_tables.size();
        Node *prev = nullptr;
        Node *cur = this->_tables[hashi];
        while (cur) {
            if (kot(cur->_data) == key) {
                if (prev == nullptr) {
                    this->_tables[hashi] = cur->_next;
                } else {
                    prev->_next = cur->_next;
                }
                delete cur;
                return true;
            } else {
                prev = cur;
                cur = cur->_next;
            }
        }
        return false;
    }

    // �����Ż���ʹ����������
    size_t GetNextPrime(size_t prime) {
        // SGI
        static const int _stl_num_primes = 28;
        static const uint64_t _stl_prime_list[_stl_num_primes] = {
                53, 97, 193, 389, 769, 1543,
                3079, 6151, 12289, 24593, 49157, 98317,
                196613, 393241, 786433, 1572869, 3145739, 6291469,
                12582917, 25165843, 50331653, 100663319, 201326611, 402653189,
                805306457, 1610612741, 3221225473, 4294967291};

        size_t i = 0;
        for (; i < _stl_num_primes; ++i) {
            if (_stl_prime_list[i] > prime)
                return _stl_prime_list[i];
        }

        return _stl_prime_list[_stl_num_primes - 1];
    }

    //�����������T���ͣ�������K������pair<K,V> ͨ��ģ�����������
    pair<iterator, bool> Insert(const T &data) {
        Hash hash;// �º������ڲ���ȡģ��ֵ
        KeyOft kot;
        // �Ѿ�����������Ͳ��ò�����
        iterator it = Find(kot(data));
        //���it����end()��˵���ҵ��������Ͳ��ò��룬���ص�������false
        if (it != end()) {
            return make_pair(it, false);
        }


        // �������� == 1ʱ����
        if (this->n == this->_tables.size()) {
            // size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
            size_t newsize = this->GetNextPrime(_tables.size());
            vector<Node *> newtables(newsize, nullptr);
            for (auto &cur: this->_tables) {// cur��Node*
                while (cur) {
                    // ������һ��
                    Node *next = cur->_next;
                    // ͷ�嵽�±�
                    size_t hashi = hash(kot(cur->_data)) % newtables.size();
                    cur->_next = newtables[hashi];
                    newtables[hashi] = cur;

                    cur = next;
                }
            }
            _tables.swap(newtables);
        }

        size_t hashi = hash(kot(data)) % this->_tables.size();
        // ͷ��
        Node *newnode = new Node(data);
        newnode->_next = _tables[hashi];
        _tables[hashi] = newnode;
        this->n++;

        //����ɹ����أ�ͨ��newnode����this���������������true��
        return make_pair(iterator(newnode, this), true);
    }

    // ��ȡ��ϣ��������󳤶�(��ϣͰ����)
    size_t MaxBucketSize() {
        size_t max = 0;
        for (int i = 0; i < _tables.size(); ++i) {
            auto cur = _tables[i];
            size_t size = 0;
            while (cur) {
                ++size;
                cur = cur->_next;
            }

            printf("[%d]->%d\n", i, size);

            if (size > max) {
                max = size;
            }
            if (max == 5121) {
                printf("%d", i);
                break;
            }
        }

        return max;
    }

private:
    vector<Node *> _tables;
    size_t n = 0;// �洢��Ч���ݵĸ���
};