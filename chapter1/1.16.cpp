#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int value;
  int sum = 0;
  while (cin >> value) {
    sum += value;
  }
  cout << "sum is ";
  cout << sum << endl;
  return 0;
}
