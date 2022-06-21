#include "LinearProbingTable.h"

#include <cmath>
#include <string>

LinearProbingTable::LinearProbingTable(int tableSize) {
    this->capacity = tableSize;
    this->size = 0;
    this->cells = std::vector<HashNode>(tableSize);
    for (int i = 0; i < tableSize; i++)
        cells[i].state = FREE;
}

[[maybe_unused]] LinearProbingTable::LinearProbingTable(const LinearProbingTable& table) {
    this->capacity = table.capacity;
    this->size = table.size;
    this->cells = std::vector<HashNode>(this->capacity);
    for (int i = 0; i < this->capacity; i++) {
        this->cells[i].value = table.cells[i].value;
        this->cells[i].key = table.cells[i].key;
        this->cells[i].state = table.cells[i].state;
    }
}

int LinearProbingTable::hash(TKey key) {
    int hashResult = 0;
    for (char i : key)
        hashResult = ((capacity - 1) * hashResult + (int) i) % capacity;
    hashResult = (hashResult * 2 + 1) % capacity;
    return abs(hashResult);
}

void LinearProbingTable::rehash() {
    // Save old 'key - value' pairs in temporary array
    auto tempCells = cells;
    // Change inner state of table
    resize();

    // Move old buckets to the new table
    for (int i = 0; i < capacity / 2; i++) {
        if (tempCells[i].state == BUSY) {
            insert(tempCells[i].key, tempCells[i].value);
        }
    }

    // Free up the memory allocated for temporary array
    tempCells.clear();
    tempCells.shrink_to_fit();
}

void LinearProbingTable::resize() {
    // Increase the capacity of table
    capacity *= 2;

    // Allocate memory for buckets in table according to the new capacity
    cells.clear();
    cells.resize(capacity);
    for (int i = 0; i < capacity; i++) {
        cells[i].state = FREE;
    }
}

void LinearProbingTable::insert(TKey key, TValue value) {
    if (size == capacity) {
		rehash();
	}

	int index = hash(key);

	while (cells[index].state == BUSY) {
		index = (index + 1) % capacity;
	}

	cells[index].key = key;
	cells[index].value = value;
	cells[index].state = BUSY;

	size++;
}

bool LinearProbingTable::remove(TKey key) {
    int index = hash(key);
	int iteration = 0;

	while (cells[index].state != FREE && cells[index].key != key && iteration < capacity) {
		index = (index + 1) % capacity;
		iteration++;
	}

	if (cells[index].state == FREE || iteration >= capacity) {
		return false;
	}

	cells[index].state = REMOVED;
	size--;
	return true;
}


bool LinearProbingTable::find(TKey key) {
    int index = hash(key);
	int iteration = 0;

	while (cells[index].state != FREE && cells[index].key != key && iteration < capacity) {
		index = (index + 1) % capacity;
		iteration++;
	}
	return iteration != capacity && cells[index].state == BUSY;
}

TValue LinearProbingTable::get(const TKey& key) {
    int index = hash(key);
	int iteration = 0;
	
	while(cells[index].state != FREE && cells[index].key != key && iteration < capacity) {
		index = (index + 1) % capacity;
		iteration++;
	}

    if (iteration == capacity || cells[index].state == FREE)
        throw std::runtime_error("Error: element is not found");

    return cells[index].value;
}



void LinearProbingTable::clear() {
    for (int i = 0; i < capacity; i++)
        cells[i].state = FREE;

    size = 0;
}

int LinearProbingTable::getSize() {
    return size;
}

bool LinearProbingTable::isEmpty() {
    return size == 0;
}

void LinearProbingTable::print() {
    for (int i = 0; i < capacity; i++) {
        std::cout << "[" << i << "]: ";
        if (cells[i].state == BUSY) {
            std::cout << cells[i].value << "(" << cells[i].key << ") ";
        }
        std::cout << std::endl;
    }
}

LinearProbingTable::~LinearProbingTable() {
    cells.clear();
    cells.shrink_to_fit();
}