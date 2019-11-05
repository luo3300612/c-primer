#include<string>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  string s = "ab2c3d7R4E6";
  string target = "0123456789";
  string::size_type pos = 0;
  while((pos=s.find_first_not_of(target,pos))!=string::npos){
    cout << "found at index:" << pos << "element is " << s[pos] << endl;
    ++pos;
  }
  // cout << pos << endl;
}