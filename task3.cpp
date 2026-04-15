#include<iostream>
using namespace std;

int arr[100];
int front = -1, rear = -1;
int cnt = 0, limit;

bool isfull() {
    return cnt == limit;
}

bool isempty() {
    return cnt == 0;
}

void enqueue(int v) {
    if (isfull()) {
        cout << "Queue Overflow\n";
        return;
    }

    if (isempty()) {
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % limit;
    }

    arr[rear] = v;
    cnt++;

    cout << "Enqueued: " << v << endl;
}

void dequeue() {
    if (isempty()) {
        cout << "Queue Underflow\n";
        return;
    }

    cout << "Dequeued: " << arr[front] << endl;

    if (front == rear) {
        front = rear = -1;
    }
    else {
        front = (front + 1) % limit;
    }

    cnt--;
}

void peek() {
    if (isempty()) cout << "Queue is Empty\n";
    else cout << "Front: " << arr[front] << endl;
}

void display() {
    if (isempty()) {
        cout << "Queue is Empty\n";
        return;
    }

    cout << "Queue: ";
    for (int i = 0; i < cnt; i++) {
        cout << arr[(front + i) % limit] << " ";
    }
    cout << endl;
}

int main() {
    int ch, v;

    cout << "Enter queue size: ";
    cin >> limit;

    do {
        cout << "\n1 Enqueue\n2 Dequeue\n3 Peek\n4 Display\n5 Exit\n";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter value: ";
            cin >> v;
            enqueue(v);
        }
        else if (ch == 2) dequeue();
        else if (ch == 3) peek();
        else if (ch == 4) display();

    } while (ch != 5);

    cout << "Program Ended\n";
}