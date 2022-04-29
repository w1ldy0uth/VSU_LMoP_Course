#pragma once

#include <iostream>
#include "HashTable.h"

class SeparateChainingTable : public HashTable {
	int capacity;
	int size;

	struct Node {
		TKey key;
		TValue value;
		Node* next;
	};

	Node** cells;

public:
	SeparateChainingTable(int tableSize);
	SeparateChainingTable(const SeparateChainingTable& table);

	void insert(TKey key, TValue value);
	bool remove(TKey key);
	bool find(TKey key);

	void clear();

	int getSize();
	bool isEmpty();

	TValue get(TKey key);

	void print();

	~SeparateChainingTable();

protected:
	int hash(TKey key);
};