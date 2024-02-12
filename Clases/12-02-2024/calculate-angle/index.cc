#include<iostream>

using namespace std;

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

int main () {
  Point p1;
  p1.print();

}