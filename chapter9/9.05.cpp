#include <iostream>
#include <vector>
using namespace std;

vector<int>::iterator find_num(vector<int>::iterator begin, vector<int>::iterator end, int n) {
  while (begin != end) {
    if (*begin == n) {
      return begin;
    }
    begin++;
  }
  return end;
}

int main(int argc, char const *argv[]) {
  vector<int> v = {1, 2, 3, 342, 5, 235, 23, 536, 46, 34, 5, 2345, 34, 5, 2};
  auto res = find_num(v.begin(), v.end(), 52222); 
  if(res==v.end()) cout << "not found" << endl;
  else{cout<<"*res"<< endl;}
}