#include<iostream>
#include<cmath>
#include<unistd.h>

//define colors
#define GREEN   "\033[32m"
#define RESET   "\033[0m"
using namespace std;


class Point
{
private:
  //the point
  double x;
  double y;
  //the point q
  double xq;
  double yq;
public:
  //this is the constructor
  Point() { x = 0; y = 0; xq = 0; yq = 0;};
  Point (double x, double y) { this->x = x; this->y = y; };
  //For print points
  void print() { cout << GREEN"The point is: " << x << ", " << y << endl; };
  void printq() { cout << GREEN"The point q is: " << xq << ", " << yq << endl; };
  //For move points
  void move(double dx, double dy) { x += dx; y += dy; };
  void moveq(double dx, double dy) { xq += dx; yq += dy; };
  //For calculate the angle of the point
  void angle() { cout << GREEN"The angle of the point is: " << atan2(y, x) << " radians." << endl; };
  //Distance between p and q
  void distance() { cout << GREEN"The distance between the points is: " << sqrt(pow(x-xq, 2) + pow(y-yq, 2)) << endl; };

};

class Vector
{
private:
  double x;
  double y;
public:
 //This is the constructor
  Vector() { x = 0; y = 0; };
  Vector (double x, double y) { this->x = x; this->y = y; };
  //For print vectors
  void print() { cout << GREEN"The vector is: " << x << "i, " << y << "j" << endl; };
  //for sum vectors
  void sum(Vector v) { x += v.x; y += v.y; };
  // for product point
  void product(Vector v) { cout << GREEN"The product of the vectors is: " << x*v.x + y*v.y << endl; };
  //for multiply by a scalar
  void multiply(double scalar) { x *= scalar; y *= scalar; };
};

//the points and the vector
Point p1;
Vector v1;

//a void for the menu
void menu() {
  cout << RESET"1. Print the point" << endl;
  cout << "2. Print the point q" << endl;
  cout << "3. Move the point" << endl;
  cout << "4. Move the point q" << endl;
  cout << "5. Calculate the angle of the point" << endl;
  cout << "6. Calculate the distance between the points" << endl;
  cout << "7. Print the vector" << endl;
  cout << "8. Sum the vector" << endl;
  cout << "9. Product the vector" << endl;
  cout << "10. Multiply the vector by a scalar" << endl;
  cout << "0. Exit" << endl;
}

//the options
void option1() {
  p1.print();
}

void option2() {
  p1.printq();
}

void option3() {
  double dx, dy;
  cout << "Enter the value of dx: ";
  cin >> dx;
  cout << "Enter the value of dy: ";
  cin >> dy;
  p1.move(dx, dy);
}

void option4() {
  double dx, dy;
  cout << "Enter the value of dx: ";
  cin >> dx;
  cout << "Enter the value of dy: ";
  cin >> dy;
  p1.moveq(dx, dy);
}

void option5() {
  p1.angle();
}

void option6() {
  p1.distance();
}

void option7() {
  v1.print();
}

void option8() {
  double x, y;
  cout << "Enter the value of x: ";
  cin >> x;
  cout << "Enter the value of y: ";
  cin >> y;
  Vector v2(x, y);
  v1.sum(v2);
}

void option9() {
  double x, y;
  cout << "Enter the value of x: ";
  cin >> x;
  cout << "Enter the value of y: ";
  cin >> y;
  Vector v2(x, y);
  v1.product(v2);
}

void option10() {
  double scalar;
  cout << "Enter the value of the scalar: ";
  cin >> scalar;
  v1.multiply(scalar);
}

//the main

int main () {
  int option;
  do {
    sleep(2);
    //clear the screen
    cout << "\033[2J\033[1;1H";
    menu();
    cout << "Enter the option: ";
    cin >> option;
    switch (option) {
      case 1:
        option1();
        break;
      case 2:
        option2();
        break;
      case 3:
        option3();
        break;
      case 4:
        option4();
        break;
      case 5:
        option5();
        break;
      case 6:
        option6();
        break;
      case 7:
        option7();
        break;
      case 8:
        option8();
        break;
      case 9:
        option9();
        break;
      case 10:
        option10();
        break;
      default:
        break;
    }
  } while (option != 0);
  return 0;
}
