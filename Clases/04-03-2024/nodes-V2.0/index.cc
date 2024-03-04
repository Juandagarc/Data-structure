#include "list.hh" // Cambiar de lista.hh a lista.h
#include <iostream>

int main() {
    node* head = nullptr;
    push_front(head, 5);
    push_front(head, 4);
    push_front(head, 3);
    push_front(head, 2);
    push_front(head, 1);
    push_back(head, 6);
    push_back(head, 7);
    push_back(head, 8);
    push_back(head, 9);
    push_back(head, 10);
    pop_front(head);
    pop_back(head);
    print(head);
    std::cout << std::endl;
    node* lista2 = nullptr;
    push_front(lista2, 5);
    push_front(lista2, 5);
    print(lista2);
    return 0;
}

/* RUN COMANDS:
g++ index.cc functions.cc -o main
./main.exe
*/