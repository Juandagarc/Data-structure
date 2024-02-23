#include<iostream>
#include<vector>

//define colors
#define GREEN   "\033[32m"
#define CIAN   "\033[36m"
#define RESET   "\033[0m"

using namespace std;


class Point
{
private:
  double X;
  double Y;
  double Z;
public:
  Point() { X = 0; Y = 0; Z = 0; };//this is the constructor
  Point(double x, double y, double z) { this->X= x; this->Y = y; this->Z = z; 
  cout << GREEN "Constructor called for Point object" RESET << endl;
  };//this is the constructor
  void print() { cout << "The point is: (" << X << ", " << Y << ", " << Z << ")" << endl; };//this is for print the point
  void move(double dx, double dy, double dz) { X += dx; Y += dy; Z += dz; };//this is for move the point
  //Do the destructor
  ~Point() {
    cout << GREEN "Destructor called for Point object" RESET << endl;
  }
};
//typename for the vector and the point
template <typename T>
class Vector
{
private:
  T *storage;
  int size;
  int capacity;
public:
  Vector(int n) { size = 0; capacity = n; storage = new int[n];
  cout << GREEN "Constructor called for Vector object" RESET << endl;
  };//this is the constructor
  void print() {
  for (int i = 0; i < size; i++)
    {
      if (i == size - 1)
      {
        cout << storage[i] << ")" << endl;
      }
      else
      {
        cout << storage[i] << ", "; };//this is for print the vector
    }
  }

  void resize(int n) {
    int *temp = new int[n];
    for (int i = 0; i < size; i++)
    {
      temp[i] = storage[i];
    }
    delete [] storage;
    storage = temp;
    capacity = n;
  };//this is for resize the vector

  void push_back(int n) { resize(n); if (size < capacity) storage[size++] = n; };//this is for add a number to the vector

  void show_atribs() { cout << CIAN "Size: " << size << " Capacity: " << capacity << "" RESET << endl; };//this is for show the size and the capacity of the vector
  ~Vector() {
    cout << GREEN "Destructor called for Vector object" RESET << endl;
    delete [] storage;
  }

};


int main () {
  Point p1(1, 2, 3);
  Point *Pp1= &p1;
  Pp1->print();
  Pp1->move(1,1,1);
  Pp1->print();

  Vector<int> v1(3);
  v1.print();
  v1.show_atribs();
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  v1.push_back(4);
  cout <<"The vector is: ("; v1.print();
  v1.show_atribs();

  return 0;
}
