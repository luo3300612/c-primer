#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> a; //默认初始化
  vector<int> b = {1, 2, 3, 4, 5, 6, 7}; // 列表初始化
  vector<int> c(b); // 拷贝初始化
  vector<int> d(10); //元素个数初始化
  vector<int> e(10,6); //元素个数加初始值初始化
  vector<int> f(b.begin(),b.end()); //迭代器初始化
  cout << "a:" << endl;
  for(auto i:a){
    cout << i << " ";
  }
  cout << endl;
  cout << "b:" << endl;
  for (auto i : b) {
    cout << i << " ";
  }
  cout << endl;
  cout << "c:" << endl;
  for (auto i : c) {
    cout << i << " ";
  }
  cout << endl;
  cout << "d:" << endl;
  for (auto i : d) {
    cout << i << " ";
  }
  cout << endl;
  cout << "e:" << endl;
  for (auto i : e) {
    cout << i << " ";
  }
  cout << endl;
  cout << "f:" << endl;
  for (auto i : f) {
    cout << i << " ";
  }
  return 0;
}