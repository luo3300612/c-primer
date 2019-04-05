#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  long double ld = 3.1415922653;
  int a{ld}, b = {ld}; // 错误：转化未执行，因为存在信息丢失的危险
  int c(ld), d = ld; // 正确：转换执行，且确实丢失了部分值
  return 0;
}
