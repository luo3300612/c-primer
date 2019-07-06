#include<iostream>

using namespace std;

void swap_point(int *&a,int *&b){
  int *tmp = b;
  b = a;
  a = tmp;
}

int main(int argc, char const *argv[])
{
  int a = 1,b=2;
  int *aa=&a,*bb=&b;

  swap_point(aa,bb);
  cout << *aa << *bb;
  return 0;
}
