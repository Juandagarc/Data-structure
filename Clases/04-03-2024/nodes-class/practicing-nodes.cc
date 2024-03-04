#include<iostream>

using namespace std;

class node
{
public:
int data;
node *next;
node(int d){
  data = d;
  next = NULL;
}
};

void push_front(node*& head, int data){
  node* new_node = new node(data);
  new_node->next = head;
  head = new_node;
}

void push_back(node*& head, int data){
  node* new_node = new node(data);
  node* current = head;
  while (current->next != nullptr)
  {
    current = current->next;
  }
  current->next = new_node;
}

void print(node* head){
  while( head != NULL ) {
    cout << head->data << " ";
    head = head->next;
  }
}

void pop_front(node* head){
  delete head;
  head = head->next;
}

void pop_back(node* head) {
  node* new_node = head;
  node* prev_node = nullptr;
  while (new_node->next != nullptr)
  {
    prev_node = new_node;
    new_node = new_node->next;
  }
  delete new_node;
  prev_node->next = nullptr;
}

int main(){
  node *head = NULL;
  push_front(head, 5);
  push_front(head, 4);
  push_front(head, 3);
  push_front(head, 2);
  push_front(head, 1);
  push_back(head,6);
  push_back(head,7);
  push_back(head,8);
  push_back(head,9);
  push_back(head,10);
  pop_front(head);
  pop_back(head);
  print(head);
  node *lista2 = NULL;
  push_front(lista2, 5);
  push_front(lista2, 5);
  cout << endl;
  print(lista2);

}
