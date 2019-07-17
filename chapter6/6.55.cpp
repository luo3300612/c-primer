#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

using PF = int (*)(int, int);

int add(int a, int b) { return a + b; }

int sub(int a, int b) { return a - b; }

int mul(int a, int b) { return a * b; }

int mydiv(int a, int b) {
  assert(b);
  return a / b;
}

int main(int argc, char const *argv[]) {
  vector<PF> v = {add, sub, mul, mydiv};
  return 0;
}
