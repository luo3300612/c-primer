#include<iostream>
#include<string>

using namespace std;

int main(int argc, char const *argv[])
{
  string s = "asdas";
  for(char i=0;i<s.size();i++){
    s[i] = 'd';
  }
  cout <<s << endl;
  return 0;
}
