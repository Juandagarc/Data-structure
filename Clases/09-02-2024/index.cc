#include<iostream>

using namespace std;

void findDiferenceOfPoints( double pointA, double pointB){
	//find the difference of the points
	double x = pointA - pointB;
	double y = pointA - pointB;
	cout << "The difference of the points is: " << x << ", " << y << endl;
};//This isn't the correct way to do it


//Other way with Point structure
struct Point {
	int x;
	int y;
};

void findDiferenceOfPoints1( Point pointA, Point pointB){
	//find the difference of the points
	double x = pointA.x - pointB.x;
	double y = pointA.y - pointB.y;
	cout << "The difference of the points is: " << x << ", " << y << endl;
};

int main() {
	int i;
	cout << i << endl;
	// use simple pointers
	int *p = &i;
	cout << *p << endl;

	// use the arrow operator
	struct structure {
		int a;
	};
	structure a;
	structure *pa = &a;

	pa->a = 5;
	cout << "This is with arrow: " << pa->a << endl;
	cout << "This is with point: " << (*pa).a << endl;
	cout << "This is other way of the point: " << a.a << endl;

	cout << "show the direction of structure: " << pa << endl;

	Point *pn1;
	Point p1 = {1, 2};
	Point p2 = {3, 4};
	//modify the x for 3 with the pointer
	pn1 = &p1;
	pn1->x = 4;

	//Show all p1
	cout << "p1.x: " << p1.x << endl;
	cout << "p1.y: " << p1.y << endl;

	//Show all p2
	cout << "p2.x: " << p2.x << endl;
	cout << "p2.y: " << p2.y << endl;

	//Show the difference of the points
	findDiferenceOfPoints(p1.x, p2.x); //Then you can see this doesn't work correctly
	findDiferenceOfPoints1(p1, p2);
  return 0;
}