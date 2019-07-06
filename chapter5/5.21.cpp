#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  string s,lasts;
  while(cin>>s){
    if(islower(s[0])){
      lasts = "";
      continue;
    }
    if(s==lasts){
      cout << s;
      break;
    }
    lasts = s;
  }
  return 0;
}
