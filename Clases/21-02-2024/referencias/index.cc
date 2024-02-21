#include<iostream>

using namespace std;

int main() {
    int a = 10;
    int &b = a;
    int c = 30;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    b = 20;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    b = c;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    return 0;
}
