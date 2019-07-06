#include<iostream>
using namespace std;

void swap(int &a,int &b){
  int t = a;
  a = b;
  b = t;
}

int main(int argc, char const *argv[])
{
  int a = 10,b= 100;
  swap(a,b);
  cout << a << b << endl;
  return 0;
}
