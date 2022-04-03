#include "linked_list.h"
#include <iostream>

using namespace std;

int main() {
    TList llist;
    init(llist);
    addToHead(llist, 13);
    for(int i = 0; i < 5; ++i)
        addToHead(llist, i);
    print(llist);
    return 0;
}
