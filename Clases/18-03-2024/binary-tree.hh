#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>

template <typename T>
class SearchBinaryTree {
private:

    /**
     * @brief Define the class Node for the binary tree
     */
    class Node {
    private:
        T value;
        Node* left;
        Node* right;

    public:

        // Constructor
        Node   () : value(), left(nullptr), right(nullptr) {}
        Node(const T& val) : value(val), left(nullptr), right(nullptr) {}

        /**
         * @brief Get the Value object
         *
         * @return const T&
         */

        const T& getValue() const {
            return value;
        }

        /**
         * @brief Get the Left object
         *
         * @return Node*
         */

        Node* getLeft() const {
            return left;
        }
        /**
         * @brief Get the Right object
         *
         * @return Node*
         */
        Node* getRight() const {
            return right;
        }
        /**
         * @brief Set the Left object
         *
         * @param leftNode
         */

        void setLeft(Node* leftNode) {
            left = leftNode;
        }
        /**
         * @brief Set the Right object
         *
         * @param rightNode
         */
        void setRight(Node* rightNode) {
            right = rightNode;
        }

        /**
         * @brief Set the Value object
         * 
         * @param val
         */
        void setValue(const T& val) {
            value = val;
        }
    };

    // Attributes
    Node* root;
    unsigned int size_;

    // Methods


    /**
     * @brief Insert a value in the tree
     *
     * @param node
     * @param val
     */
    void insertRecursive(Node* node, const T& val) {
        if (node->getValue() == val) {
            return;
        }
        if (val < node->getValue()) {
            if (node->getLeft() != nullptr) {
                insertRecursive(node->getLeft(), val);
            } else {
                node->setLeft(new Node(val));
            }
        } else {
            if (node->getRight() != nullptr) {
                insertRecursive(node->getRight(), val);
            } else {
                node->setRight(new Node(val));
            }
        }
    }

    /**
     * @brief Print the tree
     *
     * @param node
     */

    void printRecursive(const Node* node) const {
        if (node != nullptr) {
            printRecursive(node->getLeft());
            std::cout << node->getValue() << std::endl;
            printRecursive(node->getRight());
        }
    }

    /**
     * @brief Delete a node in the tree
     *
     * @param parent
     * @param node
     */
    void deleteNode(Node* parent, Node* node) {
        if (node->getLeft() == nullptr && node->getRight() == nullptr) {
            if (parent->getLeft() == node) {
                parent->setLeft(nullptr);
            } else {
                parent->setRight(nullptr);
            }
            delete node;
        } else if (node->getLeft() != nullptr && node->getRight() == nullptr) {
            if (parent->getLeft() == node) {
                parent->setLeft(node->getLeft());
            } else {
                parent->setRight(node->getLeft());
            }
            delete node;
        } else if (node->getLeft() == nullptr && node->getRight() != nullptr) {
            if (parent->getLeft() == node) {
                parent->setLeft(node->getRight());
            } else {
                parent->setRight(node->getRight());
            }
            delete node;
        } else {
            Node* temp = node->getRight();
            while (temp->getLeft() != nullptr) {
                temp = temp->getLeft();
            }
            T value = temp->getValue();
            deleteRecursive(root, temp->getValue());
            node->setValue(value);
        }
    }
    /**
     * @brief Delete an element in the tree
     *
     * @param node
     * @param val
     */
    void deleteRecursive(Node* node, const T& val) {
        if (node == nullptr) {
            return;
        }
        if (val < node->getValue()) {
            if (node->getLeft() != nullptr) {
                if (node->getLeft()->getValue() == val) {
                    deleteNode(node, node->getLeft());
                } else {
                    deleteRecursive(node->getLeft(), val);
                }
            }
        } else {
            if (node->getRight() != nullptr) {
                if (node->getRight()->getValue() == val) {
                    deleteNode(node, node->getRight());
                } else {
                    deleteRecursive(node->getRight(), val);
                }
            }
        }
    }

    /**
     * @brief  Find a value in the tree
     *
     * @param node
     * @param val
     * @return true
     * @return false
     */

    bool findRecursive(const Node* node, const T& val) const {
        if (node == nullptr) {
            return false;
        }
        if (val == node->getValue()) {
            return true;
        }
        if (val < node->getValue()) {
            return findRecursive(node->getLeft(), val);
        }
        return findRecursive(node->getRight(), val);
    }

    /**
     * @brief Clear the tree
     * 
     * @param n 
     */

    void clear(Node* n) {
        if (n != nullptr) {
            clear(n->getLeft());
            clear(n->getRight());
            delete n;
        }
    }

public:

    // Constructor
    SearchBinaryTree() : root(nullptr), size_(0) {}
    // Destructor
    ~SearchBinaryTree() {
        clear(root);
    }

    /**
     * @brief Defines if the tree is empty
     *
     * @return true
     * @return false
     */
    bool empty() const {
        return root == nullptr;
    }

    /**
     * @brief Get the Size object
     *
     * @return unsigned int
     */

    void insert(const T& val) {
        if (root == nullptr) {
            root = new Node(val);
        } else {
            insertRecursive(root, val);
        }
        size_++;
    }

    /**
     * @brief Print the tree
     *
     */
    void print() const {
        printRecursive(root);
    }

    /**
     * @brief Find a value in the tree
     *
     * @param val
     * @return true
     * @return false
     */

    bool find(const T& val) const {
        return findRecursive(root, val);
    }

    /**
     * @brief Delete a value in the tree
     *
     * @param val
     */
    void remove(const T& val) {
        if (find(val)) {
            deleteRecursive(root, val);
            size_--;
        }
    }
};

#endif // BINARY_TREE
