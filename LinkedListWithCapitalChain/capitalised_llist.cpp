#include "capitalised_llist.h"

void init(TList &head) {
    head = new Node;
    head->next = nullptr;
}

void print(TList head) {
    std::cout << "Capital node -> ";
    TList p = head->next;
    while(p->next != nullptr) {
        std::cout << p->data << "-> ";
        p = p->next;
    }
    std::cout << p->data << "\n";
}

void clear(TList &head) {
    while(!isEmpty(head))
        deleteAfterNode(head);
    delete head;
    head = nullptr;
}

bool isEmpty(TList head) {
    return head->next == nullptr;
}

void addAfterNode(TList pNode, int value) {
    TList p = new Node;
    p->data = value;
    p->next = pNode->next;
    pNode->next = p;
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