#include "QuadraticProbingTable.h"

#include <cmath>
#include <string>

QuadraticProbingTable::QuadraticProbingTable(int tableSize) {
    this->capacity = tableSize;
    this->size = 0;
    this->cells = std::vector<HashNode>(tableSize);
    for (int i = 0; i < tableSize; i++)
        cells[i].state = FREE;
}

[[maybe_unused]] QuadraticProbingTable::QuadraticProbingTable(const QuadraticProbingTable& table) {
    this->capacity = table.capacity;
    this->size = table.size;
    this->cells = std::vector<HashNode>(this->capacity);
    for (int i = 0; i < this->capacity; i++) {
        this->cells[i].value = table.cells[i].value;
        this->cells[i].key = table.cells[i].key;
        this->cells[i].state = table.cells[i].state;
    }
}

int QuadraticProbingTable::hash(TKey key) {
    int hashResult = 0;
    for (char i : key)
        hashResult = ((capacity - 1) * hashResult + (int) i) % capacity;
    hashResult = (hashResult * 2 + 1) % capacity;
    return abs(hashResult);
}

void QuadraticProbingTable::rehash() {
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

void QuadraticProbingTable::resize() {
    // Increase the capacity of table
    capacity *= 2;

    // Allocate memory for buckets in table according to the new capacity
    cells.clear();
    cells.resize(capacity);
    for (int i = 0; i < capacity; i++) {
        cells[i].state = FREE;
    }
}

void QuadraticProbingTable::insert(TKey key, TValue value) {
    if (size == capacity) {
        rehash();
    }

    int index = hash(key);
    int subIndex = index;
    int counter = 1;

    while (cells[index].state == BUSY) {
        index = (subIndex + abs(counter * counter)) % capacity;
        counter++;
    }

    cells[index].key = key;
    cells[index].value = value;
    cells[index].state = BUSY;

    size++;
}

bool QuadraticProbingTable::remove(TKey key) {
    int index = hash(key);
    int subIndex = index;
    int iteration = 0;
    int counter = 0;

    while (cells[index].state != FREE && cells[index].key != key && iteration < capacity) {
        index = (subIndex + abs(counter * counter)) % capacity;
        counter++;
        iteration++;
    }

    if (cells[index].state == FREE || iteration >= capacity) {
        return false;
    }

    cells[index].state = REMOVED;
    size--;
    return true;
}


bool QuadraticProbingTable::find(TKey key) {
    int index = hash(key);
    int subIndex = index;
    int iteration = 0;
    int counter = 0;

    while (cells[index].state != FREE && cells[index].key != key && iteration < capacity) {
        index = (subIndex + abs(counter * counter)) % capacity;
        counter++;
        iteration++;
    }
    return iteration != capacity && cells[index].state == BUSY;
}

TValue QuadraticProbingTable::get(const TKey& key) {
    int index = hash(key);
    int subIndex = index;
    int iteration = 0;
    int counter = 0;

    while(cells[index].state != FREE && cells[index].key != key && iteration < capacity) {
        index = (subIndex + abs(counter * counter)) % capacity;
        counter++;
        iteration++;
    }

    if (iteration == capacity || cells[index].state == FREE)
        throw std::runtime_error("Error: element is not found");

    return cells[index].value;
}



void QuadraticProbingTable::clear() {
    for (int i = 0; i < capacity; i++)
        cells[i].state = FREE;

    size = 0;
}

int QuadraticProbingTable::getSize() {
    return size;
}

bool QuadraticProbingTable::isEmpty() {
    return size == 0;
}

void QuadraticProbingTable::print() {
    for (int i = 0; i < capacity; i++) {
        std::cout << "[" << i << "]: ";
        if (cells[i].state == BUSY) {
            std::cout << cells[i].value << "(" << cells[i].key << ") ";
        }
        std::cout << std::endl;
    }
}

QuadraticProbingTable::~QuadraticProbingTable() {
    cells.clear();
    cells.shrink_to_fit();
}