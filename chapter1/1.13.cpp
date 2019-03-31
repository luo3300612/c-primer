#include <iostream>
using namespace std;

int main() {
  int sum = 0;
  for (int i = 50; i <= 100; ++i) {
    sum += i;
  }
  cout << "1.9:" << sum << endl;
  cout << "1.10:" << endl;
  for (int i = 10; i >= 0; --i) {
    cout << i << endl;
  }
  int a1, a2;
  cout << "1.11" << endl;
  cout << "input a1,a2 s.t a1 < a2" << endl;
  cin >> a1 >> a2;
  for (; a1 <= a2; ++a1) {
    cout << a1 << endl;
  }
}