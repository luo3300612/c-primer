#include<iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
  string a;
  cin >> a;
  for(auto &c:a){ // 引用才能改变值
    c = 'a';
  }
  cout << a << endl;
  cout << a[2];  // 不可预知的后果
  return 0;
}
