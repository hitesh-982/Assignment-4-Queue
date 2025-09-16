#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int cap;

public:
    CircularQueue(int cap) {
        cap = cap;
        arr = new int[cap];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % cap == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % cap;
        arr[rear] = value;
        cout << value << " enqueued successfully" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            return;
        }

        int value = arr[front];

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % cap;
        }

        cout << value << " dequeued successfully" << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Circular Queue elements: ";

        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        else {
            for (int i = front; i < cap; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
        cout << "Front index: " << front << ", Rear index: " << rear << endl;
    }
};

int main() {
    int capacity, choice, value;

    cout << "Enter the capacity of the circular queue: ";
    cin >> capacity;

    CircularQueue cq(capacity);

    do {
        cout << "\nmenu" << endl;
        cout << "1. enqueue" << endl;
        cout << "2. dequeue" << endl;
        cout << "3. peek" << endl;
        cout << "4. display" << endl;
        cout << "5. Check  Empty" << endl;
        cout << "6. Check  Full" << endl;
        cout << "7. exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;

            case 2:
                cq.dequeue();
                break;

            case 3:
                value = cq.peek();
                if (value != -1) {
                    cout << "Front element is: " << value << endl;
                }
                break;

            case 4:
                cq.display();
                break;

            case 5:
                if (cq.isEmpty()) {
                    cout << " empty" << endl;
                } else {
                    cout << "not empty" << endl;
                }
                break;

            case 6:
                if (cq.isFull()) {
                    cout << "queue is full" << endl;
                } else {
                    cout << "queue is not full" << endl;
                }
                break;

            case 7:
                cout << "exit" << endl;
                break;

            default:
                cout << "invalid" << endl;
        }
    } while (choice != 7);

    return 0;
}
