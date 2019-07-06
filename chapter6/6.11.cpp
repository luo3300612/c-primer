#include<iostream>
using namespace std;

void reset(int &a){
  a = 10;
}

int main(int argc, char const *argv[])
{
  /* code */
  int a = 100;
  reset(a);
  cout << a << endl;
  return 0;
}
