#pragma once

#include <string>

typedef std::string TKey;
typedef int TValue;

class HashTable {
public:
    virtual void insert(TKey key, TValue value) = 0;
    virtual bool remove(TKey key) = 0;
    virtual bool find(TKey key) = 0;

    virtual void clear() = 0;

    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual TValue get(const TKey& key) = 0;

    virtual void print() = 0;

protected:
    virtual int hash(TKey key) = 0;
};