#include "binary-tree.hh"
#include <iostream>

using namespace std;

int main() {
  SearchBinaryTree<int> tree;
    /**
   * @brief This method will reutrn if the tree is empty
   *
   * @return true
   *
   */
  tree.empty();
  tree.insert(3);
  tree.insert(8);
  tree.insert(2);
  tree.insert(4);
  tree.insert(7);
  tree.insert(9);
  tree.print();
  /**
   * @brief The binary tree will be printed in the console
   *               3
   *             /   \
   *            2     8
   *           / \   / \
   *          ""  4 7   9
   */
  cout << endl;

  /**
   * @brief This method will return true if the value is in the tree, otherwise it will return false
   *
   * @return true
   *
   */
  cout << tree.find(3) << endl;
  /**
   * @brief This method will return false if the value is in the tree, otherwise it will return true
   *
   * @return false
   *
   */
  cout << tree.find(10) << endl;
  /**
   * @brief This method will reutrn if the tree is empty
   *
   * @return false
   *
   */
  tree.empty();

  return 0;
}