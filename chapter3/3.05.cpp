#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main(int argc, char const *argv[])
{
  string s;
  string out = "";
  while(cin>>s){
    if(s=="q"){
      break;
    }
    out += " " +  s;
  }
  cout << out << endl;
  return 0;
}
