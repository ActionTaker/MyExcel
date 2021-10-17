
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