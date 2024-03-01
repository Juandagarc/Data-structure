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

void insertAtHead(node*& head, int data)
{
  node* n = new node(data);
  n->next = head;
  head = n;
}

void insertAtEnd(node*& head, int data)
{
  node* new_node = new node(data);

  if (new_node == nullptr)
  {
    head = new_node;
    return;
  }

  node* current = head;

  while (current->next != nullptr)
  {
    current = current->next;
  }
  current->next = new_node;
}



void print(node* head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
}

void popFront(node*& head)
{
  head = head->next;
}

void popBack(node*& head)
{
  if (head->next == nullptr)
  {
    delete head;
  }
  node* current = head;
  node* prev = nullptr;
  while (current->next != nullptr)
  {
    prev = current;
    current = current->next;
  }
  delete current;
  prev->next = nullptr;
}

int main () {
  node* head = NULL;
  insertAtHead(head, 1);
  insertAtHead(head, 2);
  insertAtHead(head, 3);
  insertAtHead(head, 4);
  insertAtHead(head, 5);
  print(head);
  //------------------------------------
  cout << endl;
  //------------------------------------
  insertAtEnd(head, 1);
  insertAtEnd(head, 2);
  insertAtEnd(head, 3);
  insertAtEnd(head, 4);
  insertAtEnd(head, 5);
  print(head);

  //------------------------------------
  cout << endl;
  //------------------------------------
  popFront(head);
  popBack(head);
  print(head);
}