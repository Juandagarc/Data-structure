#ifndef _QUEUE_HH_
#define _QUEUE_HH_

#include<iostream>
#include<vector>

template <class T> class queue {
  private:
  int front, rear, size;
  unsigned cap;
  T* arr;
  public:
  /**
   * @brief Queue maker
   *
   * @return queue
   */
  queue(unsigned cap){
    this->cap = cap;
    front = size = 0;
    rear = cap - 1;
    arr = new T[(cap * sizeof(T))];
  };

  /**
   * @brief Push a new element in the queue
   *
   * @return T item
   */
  queue* push(T item){
    if(size == cap){
      return this;
    }
    rear = (rear + 1) % cap;
    arr[rear] = item;
    size = size + 1;
    return this;
  };

  /**
   * @brief Pop the last element in the queue
   *
   */
  void pop(){
    if(size == 0){
      return;
    }
    front = (front + 1) % cap;
    size = size - 1;
  };

  /**
   * @brief Print the elements in the queue
   *
   */
  void printQueue(){
    for(int i = 0; i < size; i++){
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  };


};

#endif