# MyExcel
## Code
>
```
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
```

## const MyString& lightCopy(MyString& str) 의 도입
>
두개 문자열객체가 있다고 가정해보자
```
MyString str1 = "string1";
MyString str2 = "string2";
```
그리고 str1를 str2와 같은내용으로 복사하고싶다면
```
str1 = str2;
```
위와같이 코드를 작성하면된다. 그러면 오버로딩된 =연산자는 같은 내용을 담는 그릇(char배열)을 두개 만들어서 따로따로 담는다. 만약에 여기서 str2는 더이상 쓸 필요가없다고 가정해보자. 그렇다면 char배열 두개가 과연 필요할까? str1의 string이 str2의 string의 값과 같게 해주면된다. 애초에 MyString는 힙영역에 생성된 배열을 가르키는 포인터를 감싸고있는 객체이다. 따라서 str1의 포인터를 str2가 가리키고있는 배열을 가르키게 하게하고 str2의 포인터를 null로 만들자. null만들지 않는다면 str2가 소멸할때 str2가 가리키고잇는 힙영역에 생성된 배열이 str1이 가리키고있지만 사라지기때문이다. 따라서 사라질 운명을 가진 객체를 복사할때는 lightCopy를 사용하면 좋을거같다. 여기서 사라질 운명을 가진 객체란 특정함수에서 생성된 객체거나 Vector에서 capacity를 다써서 더큰 메모리 블락을 만들때이다. 이때 큰메모리 블락은 작은메모리블락을 복사해야하는데 작은 메모리 블락은 사라질것이기 때문에 lightCopy를 사용해보자. lightCopy의 코드는 다음과 같다.
```
const MyString& lightCopy(MyString& str)
{
  string = str.string;
  length = str.length;
  capacity = str.capacity;
  str.string = NULL;
}
```

## void Vector::push_back(MyString s) 
>
```
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
```
예를들어 push_back("haha"); 를 입력햇다면 MyString(const char* ch)의 생성자가 생성되고 s로 복사된다. 매개변수가 된이상 그함수가 종료될때 사라질수밖에 없는 운명을 가진다. MyString의 배열인 data[length]에 s를 복사할때는 lightCopy를 사용하여 s가 가리키고있는 힙영역에있는 문자열을 그대로 받는다. 같은 방식으로 data의 capacity가 다차서 다시 복사할때에도 같은 방식을 이용한다. MyString들은 하나의 연속된 메모리 블락에있지만 그들이 가리키고잇는 문자열은 힙영역에 있기때문에 가능한일. 

## void Vector::remove(int x)
>
```
void Vector::remove(int x)
{
  for(int i = x+1; i < length; i++)
  {
    data[i - 1].lightCopy(data[i]);
  }
  length--;
}
```
여기서도 마찬가지로 data[x+1] 을 data[x]로 옮기는데 옮기고 난이후에는 data[x+1]을 쓸필요가 없어진다. 따라서
```
data[i - 1] = data[i];
```
대신에
```
data[i - 1].lightCopy(data[i]);
```
를 사용해준다.

# Stack
>
```
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
  string pop();
  string peek();
  bool is_empty();
  ~Stack();
};
```

## void Stack::push(MyString s)
>
```
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
```
여기서 매개변수로 s를 받았으므로 자유롭게 이용가능하다 레퍼런스로 받았다면 char배열 바꿔치기가 불가능하다. 그래서 Node안의 MyString을 light copy를 통해 복사해준다.

## MyString Stack::pop()
>
```
MyString Stack::pop()
{
  MyString s;
  s.lightCopy(current->s);
  Node* prev = current->prev;
  delete current;
  current = prev;
  return s;
}
```
현재 curr를 가리키고있는 노드의 MyString은 없어질것이다 따라서 lightCopy가 가능함 pop()내부에서 새로운 s를 만들고 lightcopy를 진행후 임시객체를 만들때 복사1회가 이루어진다.

## const MyString& Stack::peek()
>
```
const MyString& Stack::peek()
{
  return current->s;
}
```
pop과는 달리 없어지는 객체가 없으므로 복사를 피하기 위해 const MyString&으로 리턴해준다.
