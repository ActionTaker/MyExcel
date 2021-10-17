#include <iostream>
#include "MyString.h"
#include <string.h>

using namespace std;

class Vector {
  MyString* data;
  int capacity;
  int length;
 public:
  Vector(int n = 1);
  void push_back(MyString s);
  MyString& operator[](int i);
  void remove(int x);
  int size();
  void print();
  ~Vector();
};
Vector::Vector(int n): data(new MyString[n]), capacity(n), length(0) {}
Vector::~Vector()
{
  delete[] data;
}
void Vector::push_back(MyString s) 
{
  if(capacity == length)
  {
    MyString* new_string = new MyString[2 * capacity];
    for(int i = 0; i < length; i++)
    {
      new_string[i].lightCopy(data[i]);
    }
    delete[] data;
    data = new_string;
    capacity *= 2;
  }
  data[length].lightCopy(s);
  length++;
}
void Vector::print()
{
  for(int i = 0; i < length; i++)
  {
    data[i].println();
  }
}
MyString& Vector::operator[](int i)
{
  return data[i];
}
void Vector::remove(int x)
{
  for(int i = x+1; i < length; i++)
  {
    data[i - 1].lightCopy(data[i]);
  }
  length--;
}
int Vector::size()
{
  return length;
}
int main()
{
  Vector V(2);
  V.push_back("haha");
  V.push_back("haha2");
  V.push_back("haha3");
  V.print();
  V.remove(1);
  V.print();
}