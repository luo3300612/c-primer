#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int a[] = {1,2,3,4,5};
  decltype(a) bb = {2,3,4,56,6};
  auto b(a);
  b[1]=2;
  cout << b[0];
  cout << b[1];
  return 0;
}