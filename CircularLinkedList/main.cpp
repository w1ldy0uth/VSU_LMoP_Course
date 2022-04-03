#include "circular_llist.h"

int main() {
    TList rlist;
    init(rlist, 12);
    for(int i = 0; i < 5; ++i)
        addAfterNode(rlist, i);
    print(rlist);
    return 0;
}