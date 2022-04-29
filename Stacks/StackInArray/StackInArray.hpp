class Stack {
    unsigned int size
    int *arr;

public:
    Stack (const unsigned int _size) {
        size = 0;
        arr = new int[_size];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(const int val) {
        arr[size] = val;
        size++;
    }

    void pop() {
        size--;
    }

    int peek() {
        return arr[size-1];
    }

    bool isEmpty() {
        return size == 0;
    }
};
