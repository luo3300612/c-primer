#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int a[2][2] = {1, 4, 5, 6};


  for (auto &b : a) {
    for (int c : b) {
      cout << c;
    }
  }
  cout << endl;

  for (auto *i = a; i != a + 2; i++) {
    for (int *j = *i; j != *i + 2; j++) {
      cout << *j;
    }
  }
  // return 0;
}