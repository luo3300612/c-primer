#include <iostream>

using std::cout; using std::endl;

int main(int argc, char const *argv[]) {
  int s = 0;
  for (int i = 0; i <= 50; i++) {
    s += i;
  }
  cout << s << endl;
  return 0;
}
