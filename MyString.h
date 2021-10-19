#include <iostream>
#include <string.h>
using namespace std;
class MyString{
  char* string; //pointer to string
  int length;
  int capacity;
public:
  MyString();
  MyString(const char* str);
  MyString(const MyString& str);
  char& operator[](int index);
  char operator[](int index) const;
  void reserve(int size);
  MyString& assign(const MyString& str);
  MyString& insert(int index, const MyString& str);
  MyString& erase(int from, int to);
  MyString operator+(const MyString& str) const;
  ~MyString();
  const MyString& lightCopy(MyString& str);
  const MyString& operator=(const MyString& str);
  void print() const;
  void println() const;
  void printinfo() const;
};
