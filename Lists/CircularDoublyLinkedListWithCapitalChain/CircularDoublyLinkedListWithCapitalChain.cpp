include "CircularDoublyLinkedListWithCapitalChain.h"

void init(TDList &head) {
    head = new Node;
    head->next = head;
    head->prev = head;
}

bool isEmpty(TDList head) {
    return head == head->next;
}

void addAfterNode(TDList pNode, int val) {
    TDList p = new Node;
    p->data = val;
    p->next = pNode->next;
    p->prev = pNode;
    pNode->next = p;
    p->next->prev = p;
}

void addBeforeNode(TDList pNode, int val) {
    TDList p = new Node;
    p->data = val;
    p->prev = pNode->prev;
    p->next = pNode;
    p->next->prev = p;
    pNode->prev = p;
}

void deleteAfterNode(TDList head, TDList pNode) {
    if(pNode->next = head)
        pNode = head;
    TDList p = pNode->next;
    pNode->next = p->next;
    pNode->next->prev = pNode;
    p->next = nullptr;
    p->prev = nullptr;
    delete p;
    p = nullptr;
}

void deleteBeforeNode(TDList head, TDList pNode) {
    if(pNode->prev = head)
        pNode = head;
    TDList p = pNode->prev;
    pNode->prev = p->prev;
    pNode->prev->next = pNode;
    p->next = nullptr;
    p->prev = nullptr;
    delete p;
    p = nullptr;
}

void deleteByNode(TDList head, TDList &pNode) {
    if(pNode != head)
        pNode->prev->next = pNode->next;
        pNode->next->prev = pNode->prev;
        pNode->next = nullptr;
        pNode->prev = nullptr;
        delete pNode;
        pNode = nullptr;
}

void createFromTail(TDList &head) {
    init(head);
    TDList tail;
    for (int i = 0; i < 5; i++) {
        if (isEmpty(head)) {
            addAfterNode(head, i);
            tail = head->next;
        }
        else {
            addAfterNode(tail, i);
            tail = tail->next;
        }
    }
}

void createFromHead(TDList &head) {
    init(head);
    for (int i = 0; i < 5; i++) {
        addAfterNode(head, i);
    }
}

void createFromTail(TDList &head) {
    init(head);
    for (int i = 0; i < 5; i++) {
        int r = rand() % 10;
        if (isEmpty(head) || r <= head->next->data) {
            addBeforeNode(head, r);
        }
        else {
            TDList p = findPlace(head, r);
            addAfterNode(p, r);
        }
    }
}

TDList findPlace(TDList head, int val) {
    TDList p = head;
    while(p->next != head && p->next->data < val)
        p = p->next;
    return p;
}

void printDirect(TDList head) {
    TDList p = head;
    while (p->next != head) {
        cout << p->next->data << " ";
        p = p->next;
    }
    cout << "\n";
}

void printReverse(TDList head) {
    TDList p = head;
    while (p->prev != head) {
        cout << p->prev->data << " ";
        p = p->prev;
    }
    cout << "\n";
}

void clear(TDList &head) {
    while (!isEmpty(head))
        deleteAfterNode(head, head);
    head->next = nullptr;
    head->prev = nullptr;
    delete head;
    head = nullptr;
}
