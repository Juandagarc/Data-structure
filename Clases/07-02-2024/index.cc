#include <iostream>

using namespace std; //Esto es para no tener que escribir std::cout

int main() {
  cout << "Hello, World!" << endl;
  int i;
  cout << i << endl;
  //usamos punteros dsimples
  int *p;
  p = &i;
  *p = 5;
  cout << i << endl;

  //usamos punteros en punteros
  int **pp;
  pp = &p;
  **pp = 10;
  cout << i << endl;
  
  return 0;
}