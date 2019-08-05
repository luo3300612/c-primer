#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> a = {1,2,3};
  vector<int> b(a);
  cout << (a == b) << endl;
}