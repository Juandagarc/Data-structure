// Issue:
#include<iostream>

//colors
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */

//namespace
using namespace std;

class Matriz
{
  private:
    int rows;
    int cols;
    int *answer;
    int *data;
  public:
  //constructor
  Matriz(int rows, int cols  )
  {
    this->rows = rows;
    this->cols = cols;
    this->data = new int[rows*cols];
    this->answer = new int[rows];
    cout << GREEN "Matriz creada" RESET << endl;
    initialize(0);
  }

  //initialize the matrix
  void initialize(int value)
  {
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        data[i*cols+j] = value;
      }
    }

    for (int i = 0; i < rows; i++)
    {
      answer[i] = value;
    }
  }

  //print the matrix
  void print()
  {
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        cout << data[i*cols+j] << "\t";
      }
      cout << BLUE " " << answer[i] << "" RESET << endl;
    }
  }
  //add elements to the matrix
  void add(int row, int col, int value)
  {
    data[row*cols+col] = value;
    //cout << GREEN "Element added." RESET << endl;
  }

  void modifyAnswer(int row, int value)
  {
    answer[row] = value;
  }

  //apply Gauss-Jordan elimination
  void gaussJordan()
  {
    for (int i = 0; i < rows; i++)
    {
      if (data[i*cols+i] == 0)
      {
        cout << RED "Error: Division by zero." RESET << endl;
        return;
      }

      for (int j = 0; j < rows; j++)
      {
        if (i != j)
        {
          int factor = data[j*cols+i] / data[i*cols+i];
          for (int k = 0; k < cols; k++)
          {
            data[j*cols+k] -= data[i*cols+k] * factor;
          }
          answer[j] -= answer[i] * factor;
          cout << RED "------------------------" RESET << endl;
          print();
        }
      }
    }
    for (int i = 0; i < rows; i++)
    {
      answer[i] /= data[i*cols+i];
      data[i*cols+i] = 1;
    }
  }

};



int main (){
  Matriz m(3,3);

  //the matriz will be:
  m.add(0,0,1); m.add(0,1,1); m.add(0,2,-1);// 1  1 -1
  m.add(1,0,0); m.add(1,1,-1); m.add(1,2,2);// 0 -1  2
  m.add(2,0,2); m.add(2,1,1); m.add(2,2,1);//  2  1  1
  //the answer will be:
  m.modifyAnswer(0,7); // 7
  m.modifyAnswer(1,3); // 3
  m.modifyAnswer(2,9); // 9

  m.print();

  // solve the matrix
  m.gaussJordan();

  cout << "The matrix after Gauss-Jordan elimination is: " << endl;
  m.print();
}