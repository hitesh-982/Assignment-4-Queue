#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int front;
    int rear;
    int cap;
    int size;

public:
    Queue(int cap) {
        cap = cap;
        arr = new int[cap];
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
        return size == cap;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "queue if full " << value << endl;
            return;
        }
        rear = (rear + 1) % cap;
        arr[rear] = value;
        size++;
        cout << value <<"added" << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            return;
        }
        cout << arr[front] << " dequeued successfully" << endl;
        front = (front + 1) % cap;
        size--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "empty" << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "empty" << endl;
            return;
        }
        cout << "all elemnts";
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % cap;
        }
        cout << endl;
    }
};

int main() {
    int capacity, choice, value;

    cout << "enter the size ";
    cin >> capacity;

    Queue q(capacity);

    do {
        cout << "\nmenu" << endl;
        cout << "1. enqueue" << endl;
        cout << "2. dequeue" << endl;
        cout << "3. peek" << endl;
        cout << "4. display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "7. exit" << endl;
        cout << "enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                value = q.peek();
                if (value != -1) {
                    cout << "front element is: " << value << endl;
                }
                break;

            case 4:
                q.display();
                break;

            case 5:
                if (q.isEmpty()) {
                    cout << " queue is empty" << endl;
                } else {
                    cout << "queue is not empty" << endl;
                }
                break;

            case 6:
                if (q.isFull()) {
                    cout << "queue is full" << endl;
                } else {
                    cout << "Queue is not full" << endl;
                }
                break;

            case 7:
                cout << "Exiting program" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 7);

    return 0;
}
