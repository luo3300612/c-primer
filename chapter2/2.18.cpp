#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int i = 45,j=46;
  int *p = &i;
  cout << "origin: " << *p << endl;
  p = &j;
  cout << "now: " << *p << endl;
  cout << "origin j:" << j << endl;
  *p = 10;
  cout << "now j:" << j << endl;
  return 0;
}
