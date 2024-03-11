#include<iostream>
#include<vector>

class Queue {
public:
    int front, rear, size;
    unsigned cap;
    int* arr;
};

Queue* QueueMaker( unsigned cap ){
  Queue* queue = new Queue();
  queue->cap = cap;
  queue->front = queue->size = 0;

  queue->rear = cap - 1;
  queue->arr = new int[(queue->cap * sizeof(int))];
  return queue;
}

//push

Queue* Push(Queue* queue, int item){
  if(queue->size == queue->cap){
    return queue;
  }
  queue->rear = (queue->rear + 1) % queue->cap;
  queue->arr[queue->rear] = item;
  queue->size = queue->size + 1;
  return queue;
}

void printQueue(Queue* queue){
  for(int i = 0; i < queue->size; i++){
    std::cout << queue->arr[i] << " ";
  }
  std::cout << std::endl;
}

void pop(Queue* queue){
  if(queue->size == 0){
    return;
  }
  queue->front = (queue->front + 1) % queue->cap;
  queue->size = queue->size - 1;
}

int main() {
  Queue* queue = QueueMaker(10);
  std::cout << "Queue created with capacity: " << queue->cap << std::endl;
  queue = Push(queue, 10);
  queue = Push(queue, 20);
  queue = Push(queue, 30);
  queue = Push(queue, 40);
  queue = Push(queue, 50);
  printQueue(queue);
  pop(queue);
  printQueue(queue);
  return 0;
}
