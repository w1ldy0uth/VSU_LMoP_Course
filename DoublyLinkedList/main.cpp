#include "double_llist.h"

int main() {
    TDList head;
    TDList tail = init(head, 12);
    for(int i = 0; i < 5; i++)
        addAfterNode(head, tail, i);
    printDirect(head);
    printReverse(tail);
    return 0;
}

