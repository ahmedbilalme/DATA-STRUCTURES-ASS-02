#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int v) { data = v; next = NULL; }
};

class stack {
    node* top;
    int size, limit;

public:
    stack(int l) { top = NULL; size = 0; limit = l; }

    bool isempty() { return top == NULL; }
    bool isfull() { return size == limit; }

    void push(int v) {
        if (isfull()) { cout << "Overflow\n"; return; }
        node* n = new node(v);
        n->next = top;
        top = n;
        size++;
    }

    void pop() {
        if (isempty()) { cout << "Underflow\n"; return; }
        node* t = top;
        top = top->next;
        delete t;
        size--;
    }

    void peek() {
        if (isempty()) cout << "Empty\n";
        else cout << top->data << endl;
    }

    void display() {
        node* t = top;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main() {
    stack s(5);
    int ch, v;

    do {
        cout << "\n1 push 2 pop 3 peek 4 display 5 exit\n";
        cin >> ch;

        if (ch == 1) { cin >> v; s.push(v); }
        else if (ch == 2) s.pop();
        else if (ch == 3) s.peek();
        else if (ch == 4) s.display();

    } while (ch != 5);
}