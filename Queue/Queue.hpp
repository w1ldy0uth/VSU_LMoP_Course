struct Node {
    int data;
    Node *next;
};

typedef Node* TQueue

class Queue {
    TQueue front, rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    ~Queue() {
        while(!isEmpty())
            dequeue();
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int val) {
        TQueue p = new Node;
        p->data = val;
        p->next = nullptr;
        if(!isEmpty()) {
            rear->next = p;
            rear = p;
        }
        else
            head = tail = p;
    }

    void dequeue() {
        if(!isEmpty()) {
            TQueue p = front;
            front = front->next;
            delete p;
            p = nullptr;
        }
    }

    int getFront() {
        return head->data;
    }
};
