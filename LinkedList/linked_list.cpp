#include "linked_list.h"
#include <iostream>


void init(TList &head) {
    head = nullptr;
}

void print(TList head) {
    TList p = head;
    while(p != nullptr) {
        std::cout << p->data << " -> ";
        p = p->next;
    }
    std::cout << "\n";
}

void clear(TList &head) {
    while (!isEmpty(head)) {
        deleteFromHead(head);
    }
}

bool isEmpty(TList head) {
    return head == nullptr;
}

void addToHead(TList &head, int value) {
    TList p = new Node;
    p -> data = value;
    p -> next = head;
    head = p;
}

void addAfterNode(TList pNode, int value) {
    TList p = new Node;
    p->data = value;
    p->next = pNode->next;
    pNode->next = p;
}

void deleteFromHead(TList &head) {
    TList p = head;
    head = head->next;
    p->next = nullptr;
    delete p;
    p = nullptr;
}

void deleteAfterNode(TList pNode) {
    TList p = pNode->next;
    if (p != nullptr) {
        pNode->next = p->next;
        p->next = nullptr;
        delete p;
        p = nullptr;
    }
}