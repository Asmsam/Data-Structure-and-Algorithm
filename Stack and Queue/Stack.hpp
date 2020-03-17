#include <iostream>
using namespace std;

struct Node {
    unsigned char data;
    struct Node* next;
};

class Stack {
    struct Node* top;

    public:
    Stack();
    void push(char value);
    void pop();
};

Stack::Stack() {
    top == NULL;
}

void Stack::push(char value) {
    struct Node* p = new struct Node;
    p->data = value;
    p->next = top;
    top = p;
}

void Stack::pop() {
    if( top == NULL ) cout << "Stack Underflow" << endl;
    else {
        cout << "The popped element is " << top->data << endl;
        top = top->next;
    }
}
