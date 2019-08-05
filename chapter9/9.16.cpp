#include<iostream>
#include<list>
#include<vector>

using namespace std;

int main(int argc, char const *argv[]) {
  list<int> a = {1,2,3};
  vector<int> b = {4,5,6};
  vector<int> c;
  c.assign(a.cbegin(),a.cend());
  cout << (b==c) << endl;
}