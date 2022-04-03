#include "capitalised_llist.h"
#include <iostream>

using namespace std;

int main() {
    TList clist;
    init(clist);
    for(int i = 0; i < 5; ++i)
        addAfterNode(clist, i);
    print(clist);
    clear(clist);
    return 0;
}
