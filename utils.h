#ifndef UTILS_H
#define UTILS_H
#include "MyString.h"


namespace MyExcel{
class Stack {
  struct Node {
    Node* prev;
    MyString s;
  };
  Node* current;
  Node* start;
 public:
  Stack();
  void push(MyString s);
  MyString pop();
  const MyString& peek();
  bool is_empty();
  ~Stack();
};
Stack::Stack()
{
  current = start = NULL;
}
void Stack::push(MyString s)
{
  if(start == NULL)
  {
    start = new Stack::Node;
    current = start;
    start->prev = NULL;
    start->s.lightCopy(s);
    return;
  }
  Node* temp = new Stack::Node;
  temp->prev = current;
  temp->s.lightCopy(s);
  current = temp;
}
MyString Stack::pop()
{
  MyString s;
  s.lightCopy(current->s);
  if(current == start)
  {
    delete current;
    start = current = NULL;
  }
  else
  {
    Node* prev = current->prev;
    delete current;
    current = prev;
  }
  return s;
}
bool Stack::is_empty()
{
  return start == NULL;
}
Stack::~Stack()
{
  if(!start)
  {
    while(start != current)
    {
      Node* prev = current->prev;
      delete current;
      current = prev;
    }
    delete start;
  }
}
const MyString& Stack::peek()
{
  return current->s;
}
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
}