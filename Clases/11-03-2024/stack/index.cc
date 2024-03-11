#include<iostream>
#include"stack.hh"

int main() {
  Stack<int> stack;
  stack.push(10);
  stack.push(20);
  stack.push(30);
  stack.push(40);
  stack.push(50);
  stack.printStack();
  stack.pop();
  stack.printStack();
  return 0;
}