#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[]) {
  vector<char> v = {'a','e','i','o','u'};
  string s;
  for(auto i:v){
    s.push_back(i);
  }
  cout << s << endl;
  //string s(v.data(),v.size());
}