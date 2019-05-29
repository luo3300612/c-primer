#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
  string s1;
  string s2;
  cin >> s1 >> s2;
  if (s1==s2){
    cout << "eq" << endl;
  }
  else{
    cout << (s1 > s2 ? s1 : s2) << endl;
  }
  cin >> s1 >> s2;
  if (s1.size()==s2.size()){
    cout << "eq" << endl;
  }
  else{
    cout << (s1.size()>s2.size() ? s1:s2) << endl;
  }
  return 0;
}
