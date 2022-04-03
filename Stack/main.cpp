#include "stack.h"

int main() {
    TStack top;
    init(top);
    for(int i = 0; i < 5; i++)
        push(top, i);
    print(top);
    return 0;
}

