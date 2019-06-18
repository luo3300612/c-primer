//计算结果超过类型表示的范围称为溢出
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  unsigned int a = 0;
  a = a - 1;
  cout << a<< endl;
  int b = INT32_MAX + 1;
  cout << b << endl;
  int c = INT32_MIN - 1;
  cout << c << endl;
  return 0;
}
