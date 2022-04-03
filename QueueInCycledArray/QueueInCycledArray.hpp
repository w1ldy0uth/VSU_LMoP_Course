class Queue {
    static const int SIZE = 100;
    int *queue;
    int front, rear;

public:
    Queue() {
        queue = new int[SIZE];
        front = rear = -1;
    }

    ~Queue() {
        delete[] queue;
    }

    void enqueue(int val) {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = val;
    }

    void dequeue() {
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }

    bool isEmpty() {
        return front == -1;
    }
};
