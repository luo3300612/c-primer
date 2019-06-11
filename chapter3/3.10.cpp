#include<iostream>
#include<string>

using namespace std;

int main(int argc, char const *argv[])
{
  string s;
  cin >> s;
  for(auto &c:s){
    if(ispunct(c)){
      continue;
    }
    cout << c;
  }
}
