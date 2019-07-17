#include <iostream>
using namespace std;

void f(int a) { cout << 1 << endl; }

void f(int a, int b) { cout << 2 << endl; }

void f(double a) { cout << 3 << endl; }

void f(double a, double b = 3.14) { cout << 4 << endl; }

void f() { cout << 5 << endl; }

int main(int argc, char const *argv[]) {
  // f(2.56,42);
  f(42);
  f(42,0);
  f(2.56,3.14);
  return 0;
}
