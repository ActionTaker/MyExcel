#include "MyString.h"
MyString& MyString::erase(int index, int num)
{
  for(int i = index; i < length; i++)
  {
    string[i] = string[i+num];
  }
  length -= num;
  return *this;
}
MyString& MyString::assign(const MyString& str)
{
  if(str.capacity > capacity)
  {
    delete[] string;
    length = str.length;
    capacity = str.capacity;
    string = new char[capacity];
    for(int i = 0; i < length; i++) string[i] = str.string[i];
  }
  else
  {
    length = str.length;
    for(int i = 0; i < length; i++) string[i] = str.string[i];
  }
  return *this;
}
MyString::MyString(){};
const MyString& MyString::lightCopy(MyString& str)
{
  string = str.string;
  length = str.length;
  capacity = str.capacity;
  str.string = NULL;
  return *this;
}
MyString::MyString(const char* str)
{
  length = capacity = strlen(str);
  string = new char[capacity];
  for(int i = 0; i < length; i++)
    string[i] = str[i];
}
MyString::MyString(const MyString& str)
{
  length = str.length;
  capacity = str.capacity;
  string = new char[capacity];
  for(int i = 0; i < length; i++)
    string[i] = str.string[i];
}
char& MyString::operator[](int index)
{
  return string[index];
}

MyString& MyString::insert(int index, const MyString& str)
{
  if(capacity < str.length + length)
  {
    if(2*capacity > str.length + length) 
      capacity *= 2;
    else
      capacity = str.length + length;

    char* new_string = new char[capacity];

    for(int i = 0; i < length; i++)
      new_string[i] = string[i];

    delete[] string;
    string = new_string;
  }
  for(int i = length-1; i >= index; i--) //주석달기
    string[i + str.length] = string[i];

  for(int i = 0; i < str.length; i++)
    string[i + index] = str.string[i];
  length += str.length;
  return *this;
}

MyString MyString::operator+(const MyString& str) const
{
  MyString temp = *this;
  temp.insert(length, str);
  return temp;
}
MyString::~MyString()
{
  if(string) delete[] string;
}
const MyString& MyString::operator=(const MyString& str)
{
  return (*this).assign(str);
}


void MyString::print() const
{
  for(int i = 0; i < length; i++)
    cout << string[i];
}
void MyString::println() const
{
  for(int i = 0; i < length; i++)
    cout << string[i];
  cout << '\n';
}
void MyString::printinfo() const
{
  cout << "MyString :"; println();
  cout << "Length :" << length << '\n';
  cout << "Capacity :" << capacity << '\n';
}