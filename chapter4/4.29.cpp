#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int x[10];
  int *p = x;
  cout << sizeof(x) / sizeof(*x) << endl; // expect 10
  cout << sizeof(p) / sizeof(*p) << endl; // expect 0
  return 0;
}
