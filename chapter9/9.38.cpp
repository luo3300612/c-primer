#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> v;
  cout << v.capacity()<<endl;
  v.push_back(4);
  cout << v.capacity()<<endl;
  v.push_back(4);
  cout << v.capacity()<<endl;
  v.push_back(4);
  cout << v.capacity()<<endl;
}