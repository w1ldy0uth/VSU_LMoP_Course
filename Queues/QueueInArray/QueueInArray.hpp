class Queue {
    static const int SIZE = 100;
    int *queue;
    int front, rear;

public:
    Queue() {
        queue = new int[SIZE];
        front = rear = 0;
    }

    ~Queue() {
        delete[] queue;
    }

    void enqueue(int val) {
        rear++;
        if (rear == SIZE)
            rear = 0;
        queue[rear] = val;
    }

    void dequeue() {
        front++;
        if (front == SIZE)
            front = 0;
    }

    bool isEmpty() {
        return rear == 0;
    }
};
