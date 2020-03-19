#include <iostream>
using namespace std;

struct Node {
    unsigned char data;
    struct Node* next;
};

class Stack {
    public:
    struct Node* top = NULL;
    void Push(unsigned char value);
    void Pop();
};

void Stack::Push(unsigned char value) {
    struct Node* p = new struct Node;
    p->data = value;
    p->next = top;
    top = p;
}

void Stack::Pop() {
    if( top == NULL ) cout << "Stack Underflow" << endl;
    else {
        cout << "The popped element is " << top->data << endl;
        top = top->next;
    }
}
