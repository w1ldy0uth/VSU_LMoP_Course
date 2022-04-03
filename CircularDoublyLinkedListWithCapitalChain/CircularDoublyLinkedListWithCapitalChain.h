// боже кто вообще будет использовать это...

struct Node {
    int data;
    Node *prev;
    Node *next;
};

typedef Node* TDList

void init(TDList&);
void clear(TDList&);

void printDirect(TDList);
void printReverse(TDList);

bool isEmpty(TDList);

void addAfterNode(TDList, int);
void addBeforeNode(TDList, int);
void deleteAfterNode(TDList, TDList);
void deleteBeforeNode(TDList, TDList);
void deleteByNode(TDList, TDList&);

void createFromTail(TDList&);
void createFromHead(TDList&);
void createByOrder(TDList&);
TDList findPlace(TDList, int);
