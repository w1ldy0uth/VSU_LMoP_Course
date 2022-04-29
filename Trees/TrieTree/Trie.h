#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

const int ALPHABET_SIZE = 26;

struct Node {
    char c;
    bool eow;
    Node* symbols[ALPHABET_SIZE]{};

public:
    explicit Node(char symbol) { // CHANGED: added 'explicit' to constructor
        c = symbol;
        eow = false;
        for (auto& sym : symbols) // CHANGED: replaced range based for-cycle with foreach
             sym = nullptr;
    }

    Node(const Node& node) {
        c = node.c;
        eow = node.eow;
        for (int i = 0; i < ALPHABET_SIZE; ++i)
            symbols[i] = node.symbols[i];
    }
};

class Trie {
private:
    Node* root;

    void remove(Node*&, string&, size_t&, bool&, int); // FIXED: changed 'node' type to reference and return type to void
    static bool hasChildren(Node*);

public:
    Trie();
    ~Trie();

    void insert(const string&);
    bool find(const string&);
    void remove(string);
    void clear();
    void print();

    vector<string> getWords();
};