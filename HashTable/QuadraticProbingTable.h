#pragma once

#include "HashTable.h"
#include <iostream>
#include <vector>

class QuadraticProbingTable: public HashTable {
    int capacity;
    int size;

    const int FREE = 0;
    const int BUSY = 1;
    const int REMOVED = -1;

    struct HashNode {
        TKey key;
        TValue value;
        int state;
    };

    std::vector<HashNode> cells;

    void rehash();
    void resize();

public:
    explicit QuadraticProbingTable(int tableSize);

    [[maybe_unused]] QuadraticProbingTable(const QuadraticProbingTable& table);

    void insert(TKey key, TValue value) override;
    bool remove(TKey key) override;
    bool find(TKey key) override;

    void clear() override;

    int getSize() override;
    bool isEmpty() override;

    TValue get(const TKey& key) override;

    void print() override;

    ~QuadraticProbingTable();

protected:
    int hash(TKey key) override;
};