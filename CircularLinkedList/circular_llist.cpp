#include "circular_llist.h"

void init(TList &head, int data) {
    head = new Node;
    head->data = data;
    head->next = head;
}

void print(TList head) {
    TList p = head;
    while(p->next != head) {
        std::cout << p->data << " -> ";
        p = p->next;
    }
    std::cout << p->data << "\n";
}

void clear(TList &head) {
    while(!isEmpty(head))
        deleteAfterNode(head, head);
    delete head;
    head = nullptr;
}

bool isEmpty(TList head) {
    return head == nullptr;
}

void addAfterNode(TList pNode, int value) {
    TList p = new Node;
    p->data = value;
    p->next = pNode->next;
    pNode->next = p;
}

void deleteAfterNode(TList &head, TList pNode) {
    if(pNode->next == head)
        head = head->next;
    TList p = pNode->next;
    pNode->next = p->next;
    p->next = nullptr;
    delete p;
    p = nullptr;
}