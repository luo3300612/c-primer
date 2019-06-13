#include <iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int a[10];
  vector<int> aa;
  for (int i = 0; i < 10; i++) {
    a[i] = i;
    aa.push_back(i);
  }

  int b[10];
  for (int i = 0;i < 10;i++){
    b[i] = a[i];
  }

  vector<int> bb = aa;
  for(auto &b:bb){
    cout << b << endl;
    b = 5;
  }
  for (auto &a : aa) {
    cout << a << endl;
  }
  return 0;
}
