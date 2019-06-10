#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  string s = "asdadwq";
  for(auto &c:s){
    c = 'X';
  }
  cout << s;
  return 0;
}
