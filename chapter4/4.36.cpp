#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int a = 4;
  double b = 2;
  a *= static_cast<int>(b);
  cout << a <<endl;
  return 0;
}
