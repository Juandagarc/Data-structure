#include "list.hh"
#include <iostream>

using namespace std;

void push_front(node*& head, int data) {
    node* new_node = new node(data);
    new_node->next = head;
    head = new_node;
}

void push_back(node*& head, int data) {
    node* new_node = new node(data);
    if (head == nullptr) {
        head = new_node;
        return;
    }
    node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = new_node;
}

void print(node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

void pop_front(node*& head) {
    if (head == nullptr) return;
    node* temp = head;
    head = head->next;
    delete temp;
}

void pop_back(node*& head) {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    node* prev = nullptr;
    node* curr = head;
    while (curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = nullptr;
    delete curr;
}
