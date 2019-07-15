#include <iostream>
using namespace std;

int sum(initializer_list<int> il) {
  int s = 0;
  for (auto it : il) {
    s += it;
  }
  return s;
}

int main(int argc, char const *argv[]) {
  cout << sum({1,23,4,5,6,4});
  return 0;
 }
