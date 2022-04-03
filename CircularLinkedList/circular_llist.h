#include <iostream>

struct Node {
    int data;
    Node *next;
};

typedef Node* TList;

void init(TList&, int);
void print(TList);
void clear(TList&);

bool isEmpty(TList);

void addAfterNode(TList, int);
void deleteAfterNode(TList&, TList);