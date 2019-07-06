#include<iostream>
using namespace std;

bool have_upper(const string &s){
  for(auto i:s){
    if(isupper(i)){
      return true;
    }
  }
  return false;
}

void to_lower(string &s){
  for(auto &i:s){
    i = tolower(i);
  }
}

int main(int argc, char const *argv[])
{
  string s;
  while(cin>>s){
    cout << have_upper(s) << endl;
    to_lower(s);
    cout << s<< endl;
  }
  return 0;
}
