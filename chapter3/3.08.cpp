#include<iostream>
#include<string>

using namespace std;

int main(int argc, char const *argv[])
{
  int i = 0;
  string s = "qwwqewqe";
  while(i<s.size()){
    s[i] ='K';
    i++;
  }
  cout << s << endl;
  return 0;
}
//用for 更好，写在一起避免忘记更新控制变量