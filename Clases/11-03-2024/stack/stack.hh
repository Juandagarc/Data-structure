#ifndef _STACK_HH_
#define _STACK_HH_

#include <iostream>
#include <vector>

using namespace std;

template <class T> class Stack {
  private:
    vector<T> storage;
  public:

  /**
   * @brief  Return if the stack is empty - level of complexity O(1)
   *
   * @return true
   * @return false
   */
  bool empty() const {
    return storage.empty();
  }

  /**
   * @brief Return the number of elements in the stack - level of complexity O(1)
   *
   * @return int
   */
  int size() const {
    return storage.size();
  };

  /**
   * @brief Insert a new element in the stack - level of complexity O(1)
   *
   * @return T
   */
  void push(const T& value) {
    storage.push_back(value);
  };

  /**
   * @brief Reference to the last element in the stack - level of complexity O(1)
   *
   * @return const T&
   */
  const T& top() const {
    return storage.back();
  };

  /**
   * @brief pop the last element in the stack - level of complexity O(1)
   *
   */
  void pop() {
    storage.pop_back();
  };

  /**
   * @brief Print the elements in the stack - level of complexity O(n)
   *
   */
  void printStack() {
    for(int i = 0; i < storage.size(); i++){
      cout << storage[i] << " ";
    }
    cout << endl;
  };

};

#endif