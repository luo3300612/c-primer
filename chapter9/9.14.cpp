#include<list>
#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[]) {
  list<const char*> a = {"123","333","222"};
  vector<string> b;
  b.assign(a.cbegin(),a.cend());
  for(auto i:b){
    cout << i << " ";
  }
}