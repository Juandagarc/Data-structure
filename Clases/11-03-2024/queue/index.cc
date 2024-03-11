#include"queue.hh"
#include<iostream>

int main() {
  queue<int> queue(10);
  queue.push(10);
  queue.push(20);
  queue.push(30);
  queue.push(40);
  queue.push(50);
  queue.printQueue();
  queue.pop();
  queue.printQueue();
  return 0;
}