#include <iostream>
#include <MyString.h>

#include <string.h>

using namespace std;

class Vector {
  MyString* data;
  int capacity;
  int length;

 public:
  Vector(int n = 1);
  void push_back(MyString s);
  string operator[](int i);
  void remove(int x);
  int size();

  ~Vector();
};
Vector::Vector(int n): data(new MyString[n]), capacity(n), length(0) {}
void Vector::push_back(MyString s) 
{
  if(capacity == length) //복사과정 매우 중요! 자신이 버려질때 = 연산자 새로 정의 하자. 그래서 부족할때 char 새로안만들고 그냥 가져오기. 나머지부분은 복사하기 매개변수 s도 사라질 녀석이니 같은 방식으로 복사하자!
  {
    MyString* new_string = new MyString[2 * capacity];
    for(int i = 0; i < length; i++)
    {
      *new_string[i].getString() = *data[i].getString();
      *data[i].getString() = 0;
      
    }
    delete[] data;
    data = new_string;
    capacity *= 2;
  }
  data[length].
}