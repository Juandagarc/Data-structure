#include<iostream>

class Queue{
  public:
  int front, rear, size;
  unsigned cap;
  int* arr;
};

Queue* createQueue(unsigned cap){
  Queue* queue = new Queue();
  queue->cap = cap;
  queue->front = queue->size = 0;
};

// int main () {

// }