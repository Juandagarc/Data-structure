#ifndef LISTA_HH
#define LISTA_HH

class node {
public:
    int data;
    node* next;
    node(int d) : data(d), next(nullptr) {}  // Constructor implementation
};

void push_front(node*& head, int data);
void push_back(node*& head, int data);
void print(node* head);
void pop_front(node*& head);
void pop_back(node*& head);

#endif
