#include <iostream>
using namespace std;

class Queue {
private:
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
            return;
        }
        rear = (rear + 1) % cap;
        arr[rear] = value;
        size++;
    }
    
    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % cap;
        size--;
        return value;
    }
    
    int getSize() {
        return size;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue  empty" << endl;
            return;
        }
        cout << "queue elements: ";
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % cap;
        }
        cout << endl;
    }
};

void interleaveQueue(Queue& q) {
    int n = q.getSize();
    
    if (n <= 1) {
        return;
    }
    
    int hf = n / 2;
    int* fhf = new int[hf];
    
    for (int i = 0; i < hf; i++) {
        fhf[i] = q.dequeue();
    }
    
    int sec = n - hf;
    int* shf = new int[sec];
    
    for (int i = 0; i < sec; i++) {
        shf[i] = q.dequeue();
    }
    
    int i = 0, j = 0;
    while (i < hf && j < sec) {
        q.enqueue(fhf[i++]);
        q.enqueue(shf[j++]);
    }
    
    while (j < sec) {
        q.enqueue(shf[j++]);
    }
    
    delete[] fhf;
    delete[] shf;
}

int main() {
    int n, value;
    
    cout << "enter th enumber of elements: ";
    cin >> n;
    
    Queue q(n);
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }
    
    cout << "\nrriginal ";
    q.display();
    
    interleaveQueue(q);
    
    cout << "\nAfter interleaving ";
    q.display();
    
    return 0;
}
