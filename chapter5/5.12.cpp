#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  string s;
  getline(cin, s);
  int num_ff=0;
  int num_fl=0;
  int num_fi=0;
  bool flag = false;
  for (auto it = s.cbegin(); it != s.cend(); ++it) {
    if(flag){
      if (*it == 'f')
        ++num_ff,flag=true;
      else if (*it == 'l')
        ++num_fl,flag=false;
      else if (*it == 'i')
        ++num_fi,flag=false;
    }
    if (*it == 'f') {
      flag = true;
    }
    else{
      flag = false;
    }
  }
  cout << "ff:" << num_ff << endl;
  cout << "fl:" << num_fl << endl;
  cout << "fi:" << num_fi << endl;
  return 0;
}
