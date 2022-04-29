#include "Trie.h"

bool Trie::hasChildren(Node* node) {
    bool hasChildren = false;
    int i = 0;
    while (!hasChildren && i < ALPHABET_SIZE) {
        hasChildren = node->symbols[i] != nullptr;
        i++;
    }
    return hasChildren;
}

void Trie::remove(Node*& node, string& word, size_t& wordLength, bool& eowDeleted, int h) {
    if (node == nullptr && wordLength > 0) {
        return;
    }

    if (hasChildren(node)) { // FIXED: moved recursion so that its calls handled correctly
        char symbol = word[h];
        int index = symbol - 'a';
        remove(node->symbols[index], word, wordLength, eowDeleted, h + 1);
    }

    if (wordLength == h) {
        if (node->eow && eowDeleted)
            return;
        node->eow = false;
        eowDeleted = true;
        if (!hasChildren(node)) {
            delete node;
            node = nullptr;
        }
        wordLength--;
    }
}

Trie::Trie() {
    root = new Node('/');
}

Trie::~Trie() {
    clear();
    delete root;
    root = nullptr;
}

void Trie::insert(const string& word) {
    Node* current = root;
    for (char symbol : word) {
        int index = symbol - 'a';
        if (current->symbols[index] == nullptr) {
            current->symbols[index] = new Node(symbol);
        }

        current = current->symbols[index];
    }
    current->eow = true;
}

bool Trie::find(const string& word) {
    Node* current = root;
    for (char symbol : word) {
        int index = symbol - 'a';
        if (current->symbols[index] == nullptr) {
            return false;
        }
        current = current->symbols[index];
    }
    return current->eow;
}


void Trie::remove(string word) {
    size_t length = word.length();
    bool eowDeleted = false;
    remove(root, word, length, eowDeleted, 0);
}

void clearRecursive(Node*& node) {
    for (auto& sym : node->symbols) {
        if (sym != nullptr)
            clearRecursive(sym);
    }
    delete node;
    node = nullptr;
}

void Trie::clear() {
    if (root != nullptr)
        clearRecursive(root);
    root = new Node('/');
}

void printRecursive(Node* node, const string& word) {
    if (node != nullptr) {
        if (node->eow) {
            cout << word + node->c << '\n'; // FIXED: 'print' function didn't print last symbol of word
        }

        for (auto & symbol : node->symbols) {
            printRecursive(symbol, word + node->c);
        }
    }
}

void Trie::print() {
    for (auto & symbol : root->symbols) {
        printRecursive(symbol, "");
    }
}

void getWordsRecursive(Node* node, vector<string>& words, const string& word) {
    if (node != nullptr) {
        if (node->eow) {
            words.push_back(word + node->c);
        }

        for (auto & symbol : node->symbols) {
            getWordsRecursive(symbol, words, word + node->c);
        }
    }
}

vector<string> Trie::getWords() {
    vector<string> words;
    for (auto & symbol : root->symbols) {
        getWordsRecursive(symbol, words, "");
    }
    return words;
}