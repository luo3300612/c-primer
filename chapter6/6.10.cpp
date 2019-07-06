#include<iostream>
using namespace std;

void swap(int *a,int *b){
  int tmp = *a;
  *a=*b;
  *b = tmp;
}

int main(int argc, char const *argv[])
{
  int a=1,b=2;
  int *aa=&a,*bb=&b;
  swap(aa,bb);
  cout << a << b <<endl;
  return 0;
}
