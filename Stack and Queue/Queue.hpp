#include <iostream>
using namespace std;

struct Node {
    unsigned char data;
    struct Node* next;
};

class Queue {
    public:
    struct Node* head;
    struct Node* tail;
    struct Node* q;
    struct Node* display;
    Queue ();
    void EnQueue (unsigned char data);
    void DeQueue ();
    void Display ();
};

Queue::Queue () {
    head = NULL;
    tail = NULL;
}

void Queue::EnQueue (unsigned char data) {
    q = new struct Node;

    q->data = data;
    q->next = NULL;
    if ( head == NULL ) {
        head = q;
        tail = q;
    }
    else {
        tail->next = q;
        tail = q;
    }
}

void Queue::DeQueue () {

    q = head;
    if ( q == NULL ) {
        std::cout << "Empty!\n";
        return;
    }
    else {
        head = head->next;
        std::cout << q->data << " was dequeued.\n";
        delete q;
    }

}


void Queue::Display() {
    
    display = head;
    if ( display == NULL ) {
        std::cout << "Empty!\n";
        return;
    }
    while ( display != NULL ) {
        std::cout << display->data << " ";
        display = display->next;
    }
    std::cout << std::endl;

}