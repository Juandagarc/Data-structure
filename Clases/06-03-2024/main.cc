#include <iostream>
#include "list.hh"

using namespace std;

int main() {
    cout << "hola" << endl;
    List<int> l;
    l.print();
    l.push_back(10);
    l.print();
    l.push_front(-12);
    l.print();
    l.insert(1,5);
    l.print();
    return 0;
}

/**
 * For compile:
 * g++ index.cc list.hh -o main
 *
 * For run:
 * ./main.exe
 */