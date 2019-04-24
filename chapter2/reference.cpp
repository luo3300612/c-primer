#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
  int a = 1;
  int &b = a;
  
  cout << a << " " << b << endl;

  a = 2;
  cout << a << " " << b << endl;
  int &c = b;
  cout << c << endl;
  return 0;
}
