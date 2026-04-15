#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int v) { data = v; next = NULL; }
};

class queue {
    node* front, * rear;
    int size, limit;

public:
    queue(int l) { front = rear = NULL; size = 0; limit = l; }

    bool isempty() { return front == NULL; }
    bool isfull() { return size == limit; }

    void enqueue(int v) {
        if (isfull()) {
            cout << "Queue Overflow\n";
            return;
        }

        node* t = new node(v);

        if (isempty()) front = rear = t;
        else { rear->next = t; rear = t; }

        size++;
        cout << "Enqueued: " << v << endl;
        display();
    }

    void dequeue() {
        if (isempty()) {
            cout << "Queue Underflow\n";
            return;
        }

        node* t = front;
        cout << "Dequeued: " << front->data << endl;

        front = front->next;
        if (!front) rear = NULL;

        delete t;
        size--;

        display();
    }

    void frontval() {
        if (isempty()) cout << "Queue is Empty\n";
        else cout << "Front Element: " << front->data << endl;
    }

    void display() {
        if (isempty()) {
            cout << "Queue is Empty\n";
            return;
        }

        node* t = front;
        cout << "Queue: ";
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main() {
    int l, ch, v;

    cout << "Enter queue limit: ";
    cin >> l;

    queue q(l);

    do {
        cout << "\n1 Enqueue\n2 Dequeue\n3 Front\n4 Display\n5 Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter value: ";
            cin >> v;
            q.enqueue(v);
        }
        else if (ch == 2) q.dequeue();
        else if (ch == 3) q.frontval();
        else if (ch == 4) q.display();

    } while (ch != 5);

    cout << "Program Ended\n";
}