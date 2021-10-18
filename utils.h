#ifndef UTILS_H
#define UTILS_H
#include "MyString.h"

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
#endif
