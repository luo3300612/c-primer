#include<vector>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[]){
  vector<int> v(10,9);
  cout << v.front() << endl;
  cout << v.back() << endl;
  cout << v.at(0) << endl;
}