struct Node {
    int data;
    Node *next;
};

typedef Node* TList;

void init(TList&);
void print(TList);
void clear(TList&);

bool isEmpty(TList);

void addToHead(TList&, int);
void addAfterNode(TList, int);

void deleteFromHead(TList&);
void deleteAfterNode(TList);