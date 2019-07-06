//局部变量包括形参，局部静态变量在函数调用之后也有效
#include<iostream>
using namespace std;

int foo(int a){
  cout << a ;
  static int b=10;
  return a;
}

int main(int argc, char const *argv[])
{
  cout << foo(2) << endl;
  return 0;
}
