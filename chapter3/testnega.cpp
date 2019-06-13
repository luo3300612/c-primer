#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int a[10]={1,2,3,4,5,6,7,8,9,10};
  auto b = a + 5;
  cout << b[-2];
  return 0;
}
