#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    int x = 5;
    cout << x << endl;
    cout << &x << endl; //Esta es la ubicación de memoria
    char y = 'a';
    cout << y << endl;
    cout << &y << endl; //Esta es la ubicación de memoria
    string z = "Hola";
    cout << z << endl;
    cout << &z << endl; //Esta es la ubicación de memoria
    return 0;
}

//For run write in terminal: g++ -o main index.c++ && ./main
