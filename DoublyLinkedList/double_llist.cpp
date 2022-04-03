#include "double_llist.h"

TDList init(TDList &head, int value) {
    head = new Node;
    head->data = value;
    head->next = nullptr;
    head->prev = nullptr;
    TDList tail = head;
    return tail;
}

void printDirect(TDList head) {
    TDList p = head;
    while(p->next != nullptr) {
        std::cout << p->data << " <-> ";
        p = p->next;
    }
    std::cout << p->data << "\n";
}

void printReverse(TDList tail) {
    TDList p = tail;
    while(p->prev != nullptr) {
        std::cout << p->data << " <-> ";
        p = p->prev;
    }
    std::cout << p->data << "\n";
}

void clear(TDList &head, TDList& tail) {
    while(head->next != nullptr)
        deleteAfterNode(head, tail);
    delete head;
    head = nullptr;
    tail = nullptr;
}

bool isEmpty(TDList head) {
    return head == nullptr;
}

void addAfterNode(TDList pNode, TDList& tail, int value) {
    TDList p = new Node;
    p->data = value;
    p->next = pNode->next;
    p->prev = pNode;
    pNode->next = p;
    if(pNode == tail)
        tail = p;
    else
        p->next->prev = p;
}

void addBeforeNode(TDList pNode, TDList& head, int value) {
    TDList p = new Node;
    p->data = value;
    p->next = pNode;
    p->prev = pNode->prev;
    pNode->prev = p;
    pNode->prev = p;
    if(pNode == head)
        head = p;
    else
        p->prev->next = p;
}

void deleteAfterNode(TDList pNode, TDList& tail) {
    TDList p = pNode->next;
    pNode->next = p->next;
    p->prev = nullptr;
    if (p != tail) {
        p->next->prev = pNode;
        p->next = nullptr;
    }
    else
        tail = pNode;
    delete p;
    p = nullptr;
}

void deleteBeforeNode(TDList pNode, TDList& head) {
    TDList p = pNode->prev;
    pNode->prev = p->prev;
    p->next = nullptr;
    if (p != head) {
        p->prev->next = pNode;
        p->prev = nullptr;
    }
    else
        head = pNode;
    delete p;
    p = nullptr;
}