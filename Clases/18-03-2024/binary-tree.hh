#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>

template <class T>
class SearchBinaryTree {
private:
    struct Node {
        T value;
        Node* left;
        Node* right;

        Node(const T& val) : value(val), left(nullptr), right(nullptr) {}

        ~Node() {
            delete left;
            delete right;
        }
    };

    Node* root = nullptr;
    int treeSize = 0;

public:
    SearchBinaryTree() = default;

    ~SearchBinaryTree() {
        delete root;
    }

    bool empty() const {
        return root == nullptr;
    }

    void insert(const T& val) {
        if (empty()) {
            root = new Node(val);
        } else {
            insertRecursive(root, val);
        }
        treeSize++;
    }

    void print() const {
        printRecursive(root);
    }

    bool find(const T& val) const {
        return findRecursive(root, val);
    }

private:
    void insertRecursive(Node* node, const T& val) {
        if (val < node->value) {
            if (node->left != nullptr) {
                insertRecursive(node->left, val);
            } else {
                node->left = new Node(val);
            }
        } else {
            if (node->right != nullptr) {
                insertRecursive(node->right, val);
            } else {
                node->right = new Node(val);
            }
        }
    }

    void printRecursive(const Node* node) const {
        if (node != nullptr) {
            printRecursive(node->left);
            std::cout << node->value << std::endl;
            printRecursive(node->right);
        }
    }

    bool findRecursive(const Node* node, const T& val) const {
        if (node == nullptr) {
            return false;
        }
        if (val == node->value) {
            return true;
        }
        if (val < node->value) {
            return findRecursive(node->left, val);
        }
        return findRecursive(node->right, val);
    }
};

#endif // BINARY_TREE
