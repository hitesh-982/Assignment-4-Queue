#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int value) {
        if (isFull()) return;
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    int getSize() {
        return size;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

// stack using 2 queues
class StackTwoQ {
    Queue* q1;
    Queue* q2;
    int capacity;

public:
    StackTwoQ(int cap) {
        capacity = cap;
        q1 = new Queue(cap);
        q2 = new Queue(cap);
    }

    ~StackTwoQ() {
        delete q1;
        delete q2;
    }

    void push(int value) {
        if (q1->isFull()) {
            cout << "stack full\n";
            return;
        }
        q1->enqueue(value);
        cout << value;
        cout << " pushed\n";
    }

    int pop() {
        if (q1->isEmpty()) {
            cout << "stack empty\n";
            return -1;
        }

        while (q1->getSize() > 1) {
            q2->enqueue(q1->dequeue());
        }

        int popped = q1->dequeue();

        Queue* temp = q1;
        q1 = q2;
        q2 = temp;

        cout << popped;
        cout << " popped\n";
        return popped;
    }

    int top() {
        if (q1->isEmpty()) {
            cout << "stack empty\n";
            return -1;
        }

        while (q1->getSize() > 1) {
            q2->enqueue(q1->dequeue());
        }

        int topElement = q1->dequeue();
        q2->enqueue(topElement);

        Queue* temp = q1;
        q1 = q2;
        q2 = temp;

        return topElement;
    }

    bool isEmpty() {
        return q1->isEmpty();
    }
};

// stack using 1 queue
class StackOneQ {
    Queue* q;
    int capacity;

public:
    StackOneQ(int cap) {
        capacity = cap;
        q = new Queue(cap);
    }

    ~StackOneQ() {
        delete q;
    }

    void push(int value) {
        if (q->isFull()) {
            cout << "stack full\n";
            return;
        }

        int size = q->getSize();

        q->enqueue(value);

        for (int i = 0; i < size; i++) {
            q->enqueue(q->dequeue());
        }

        cout << value;
        cout << " pushed\n";
    }

    int pop() {
        if (q->isEmpty()) {
            cout << "stack empty\n";
            return -1;
        }

        int popped = q->dequeue();
        cout << popped;
        cout << " popped\n";
        return popped;
    }

    int top() {
        if (q->isEmpty()) {
            cout << "stack empty\n";
            return -1;
        }
        return q->getFront();
    }

    bool isEmpty() {
        return q->isEmpty();
    }
};

int main() {
    int choice, method, value;

    cout << "choose method:\n";
    cout << "1. two queues\n";
    cout << "2. one queue\n";
    cout << "enter: ";
    cin >> method;

    if (method == 1) {
        StackTwoQ st(10);

        do {
            cout << "\n1 push\n";
            cout << "2 pop\n";
            cout << "3 top\n";
            cout << "4 empty?\n";
            cout << "5 exit\n";
            cout << "enter: ";
            cin >> choice;

            if (choice == 1) {
                cout << "value: ";
                cin >> value;
                st.push(value);
            }
            else if (choice == 2) {
                st.pop();
            }
            else if (choice == 3) {
                value = st.top();
                if (value != -1) {
                    cout << "top = ";
                    cout << value << "\n";
                }
            }
            else if (choice == 4) {
                if (st.isEmpty())
                    cout << "yes\n";
                else
                    cout << "no\n";
            }
        } while (choice != 5);
    }
    else {
        StackOneQ st(10);

        do {
            cout << "\n1 push\n";
            cout << "2 pop\n";
            cout << "3 top\n";
            cout << "4 empty?\n";
            cout << "5 exit\n";
            cout << "enter: ";
            cin >> choice;

            if (choice == 1) {
                cout << "value: ";
                cin >> value;
                st.push(value);
            }
            else if (choice == 2) {
                st.pop();
            }
            else if (choice == 3) {
                value = st.top();
                if (value != -1) {
                    cout << "top = ";
                    cout << value << "\n";
                }
            }
            else if (choice == 4) {
                if (st.isEmpty())
                    cout << "yes\n";
                else
                    cout << "no\n";
            }
        } while (choice != 5);
    }

}
