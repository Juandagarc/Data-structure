#include<iostream>

void printArray (int *array, int size) {
  for (int i = 0; i < size; i++) {
    std::cout << "The element " << i << " of the array is: " << *(array+i) << std::endl;
  }
}

using namespace std;
int main () {
  int array[5] = {1, 2, 3, 4, 5};
  int *p = array;
  cout << "The first element of the array is: " << *p << endl;
  cout << "The second element of the array is: " << *(p+1) << endl;
  
  //now with for
  for (int i = 0; i < 5; i++) {
    cout << "The element " << i << " of the array is: " << *(p+i) << endl;
  }

  int *f = array;
  // cout << "The first element of the array is: " << *p << endl;
  int *pc = f + 1;
  cout << "The second element of the array is: " << *pc << endl;

  int j = 5;
  int *pj = &j;
  cout << "The value of j is: " << j << endl;
  cout << "The adress of j is: " << *pj << endl;
  int *pj2 = pj;
  cout << "The value of j is: " << j << endl;
  cout << "The adress of j is: " << *pj2 << endl;
  *pj2 += 2000;
  cout << "The value of j is: " << j << endl;
  cout << "The adress of j is: " << *pj2 << endl;


  printArray(array, sizeof(array)/sizeof(array[0]));

  class Point
  {
  private:
    double x;
    double y;
  public:
    Point() { x = 0; y = 0; };
    Point (double x, double y) { this->x = x; this->y = y; };
    void print() { cout << "The point is: " << x << ", " << y << endl; };
    void move(double dx, double dy) { x += dx; y += dy; };
  };
  Point p1;
  p1.print();
  Point p2(1, 2);
  p2.print();
  p2.move(1, 1);
  p2.print();

}
