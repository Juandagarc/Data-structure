#include<iostream>
//For vectors
#include<vector>


//for std
using namespace std;

class Vector
{
private:
  unsigned int size;
  unsigned int capacity;
  int *data;
public:
  //make the constructor
  Vector(unsigned int size, int value)
  {
    this->size = size;
    this->capacity = size;
    this->data = new int[size];//the nwe is for the size of the vector and does not have to be the same as the capacity
  }

  //initialize the vector
  void initialize()
  {
    for (int i = 0; i < size; i++)
    {
      data[i] = 0;
    }
  }

  //print the vector
  void print()
  {
    for (int i = 0; i < size; i++)
    {
      cout << data[i] << " ";
    }
    cout << endl;
  }
  //push_back function
  void push_back(int value)
  {
    if (size == capacity)
    {
      resize();
      data[size] = value;
      size++;
    }
  }

  void resize()
  {
    int *temp = new int[capacity * 2];
    for ( unsigned int i = 0; i < size; i++)
    {
      temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    capacity *= 2;
};


int main(){
  //Create a vector with {1,2,3,4}
  Vector v(4, 0);
  //initialize
  v.initialize();
  //print
  v.print();
  //push_back
  v.push_back(5);
  //print
  v.print();
    return 0;
}