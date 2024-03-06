#ifndef _LIST_HH_
#define _LIST_HH_

#include <iostream>
#include <cassert>

// Clase plantilla para una Lista genérica
template<typename T>
class List {
private:
    // Clase anidada para los nodos de la lista
    class Node {
    private:
        Node* next_; // Puntero al siguiente nodo en la lista
        Node* before_;
        T data_; // Datos del nodo

    public:
        // Constructor por defecto
        Node() : next_(nullptr), data_(T()) {}

        // Constructor con inicialización de datos
        Node(const T& d) : next_(nullptr), data_(d) {}

        // Establecer el siguiente nodo en la lista
        void setNext(Node* p) { next_ = p; }
        
        void setBefore(Node* f) { before_ = f; }

        // Obtener el siguiente nodo en la lista
        Node* getNext() { return next_; }

        // Obtener los datos del nodo
        const T& getData() const {
            return data_;
        }
        T& getData() {
            return data_;
        }

        Node* getBefore(){
          return before_;
          }
    };

    // Atributos para la Lista
    Node* first_; // Puntero al primer nodo
    Node* last_; // Puntero al último nodo
    unsigned int size_; // Tamaño de la lista

public:
    // Constructor para Lista
    List() : first_(nullptr), last_(nullptr), size_(0) {}

    // Devuelve el tamaño de la lista
    unsigned int size() const { return size_; }

    // Verifica si la lista está vacía
    bool empty() { 
        return first_ == nullptr;
    }

    // Añade un elemento al final de la lista
    void push_back(const T& elem) {
        Node* n = new Node(elem);
        if (empty()) {
            first_ = n;
        } else {
            last_->setNext(n);
            n->setBefore(last_);
        }
        last_ = n;
        size_++;
    }

    // Añade un elemento al principio de la lista
    void push_front(const T& elem) {
        Node* n = new Node(elem);
        if (empty()) {
            first_ = n;
            last_ = n;
        } else {
            n->setNext(first_);
            n->setBefore(NULL);
            first_ = n;
        }
        size_++;
    }

    // Imprime todos los elementos en la lista
    void print() {
        if (empty()) {
            std::cout << "< >" << std::endl;
            return;
        }
        Node* p = first_;
        while (p != nullptr) {
            std::cout << "(" << p->getData() 
                    << "-> " << p->getNext() 
                    << ")" << std::endl;
            p = p->getNext();
        }
        std::cout << "-----" << std::endl; 
    }

   // Método para acceder a un elemento por índice
    T& at(unsigned int index) {
    Node* current = first_; // Comienza en el primer nodo de la lista
    for (unsigned int i = 0; i < index; ++i) {
        current = current->getNext(); // Avanza current al siguiente nodo i veces
        // Esto mueve current a través de la lista hasta alcanzar el índice deseado
    }
    return current->getData(); // Devuelve los datos del nodo en el índice especificado
    // Esto permite tanto acceder como modificar el valor si es necesario
}
void insert( const T& Posn, const T& elem ) {
    Node* n= new Node(elem);
    Node *current = first_;
    assert( Posn>=0 && Posn<size_ );
    int i = 0;
    while(Posn != i+1){
      current = current->getNext();
      i++;
    }
    n->setBefore(current);
    n->setNext(current->getNext());
    current->setNext(n);
    current = current->getNext();
    current = current->getNext();
    current->setBefore(n);
  }

};

#endif