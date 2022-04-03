#include <iostream>

struct Node {
    int data;
    Node *next;
    Node *prev;
};

typedef Node* TDList;

TDList init(TDList&, int);
void printDirect(TDList);
void printReverse(TDList);
void clear(TDList&, TDList&);

bool isEmpty(TDList);

void addAfterNode(TDList, TDList&, int);
void addBeforeNode(TDList, TDList&, int);
void deleteAfterNode(TDList, TDList&);
void deleteBeforeNode(TDList, TDList&);
// TODO: deleteCurrentNode
