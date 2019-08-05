#include<list>
#include<vector>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  list<int> a = {1,2,3,4,5,6};
  vector<double> b(a.begin(),a.end());
  for(auto i:b){
    cout << i << endl;
  }
  list<int> c(b.begin(),b.end());
  for(auto i:c){
    cout << i << endl;
  }
  return 0;
}

// 用迭代器创建