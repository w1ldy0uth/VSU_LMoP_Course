#include "SeparateChainingTable.h"

SeparateChainingTable::SeparateChainingTable(int tableSize) {
	this->capacity = tableSize;
	this->size = 0;
	this->cells = new Node* [tableSize];
	for (int i = 0; i < tableSize; i++)
		this->cells[i] = nullptr;
}

SeparateChainingTable::SeparateChainingTable(const SeparateChainingTable& table) {
	this->capacity = table.capacity;
	this->size = table.size;

	this->cells = new Node* [this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->cells[i] = nullptr;

		Node* p = table.cells[i];
		while (p != nullptr) {
			Node* node = new Node;
			node->key = p->key;
			node->value = p->value;
			node->next = nullptr;

			if (this->cells[i]) {
				this->cells[i]->next = node;
			}
			else {
				this->cells[i] = node;
			}

			p = p->next;
		}
	}
}

int SeparateChainingTable::hash(TKey key) {
	int hashResult = 0;
    for (char i : key)
        hashResult = ((capacity - 1) * hashResult + (int) i) % capacity;
    hashResult = (hashResult * 2 + 1) % capacity;
    return abs(hashResult);
}

void SeparateChainingTable::insert(TKey key, TValue value) {
	int index = hash(key);

	Node* node = new Node;

	node->key = key;
	node->value = value;
	node->next = cells[index];
	
	if (cells[index] == nullptr)
		cells[index] = node;
	else {
		Node* p = cells[index];
		while(p->next != nullptr)
			p = p->next;
		p->next = node;
	}

	size++;
}

bool SeparateChainingTable::remove(TKey key)
{
	int index = hash(key);

	Node* node = cells[index];
	Node* prev = nullptr;

	while (node && node->key != key) {
		prev = node;
		node = node->next;
	}

	if (node == nullptr)
		return false;

	if (prev == nullptr) {
		cells[index] = node->next;
	}
	else {
		prev->next = node->next;
	}

	delete node;

	size--;
	return true;
}

bool SeparateChainingTable::find(TKey key)
{
	int index = hash(key);

	Node* node = cells[index];

	while (node && node->key != key)
		node = node->next;

	return node != nullptr;
}

void SeparateChainingTable::clear()
{
	for (int i = 0; i < capacity; i++) {
		while (cells[i]) {
			Node* node = cells[i];
			cells[i] = cells[i]->next;
			delete node;
		}
	}

	size = 0;
}

int SeparateChainingTable::getSize()
{
	return size;
}

bool SeparateChainingTable::isEmpty() {
	return size == 0;
}

TValue SeparateChainingTable::get(TKey key)
{
	int index = hash(key);

	Node* node = cells[index];

	while (node && node->key != key)
		node = node->next;

	if (node == nullptr)
		throw std::string("No value with this key");

	return node->value;
}

void SeparateChainingTable::print()
{
	for (int i = 0; i < capacity; i++) {
		std::cout << "[" << i << "]: ";
		Node* node = cells[i];
		while (node != nullptr){
			std::cout << node->value << "(" << node->key << ") ";
			node = node->next;
		}
		std::cout << std::endl;
	}
}

SeparateChainingTable::~SeparateChainingTable() {
	clear();
	delete[] cells;
}
