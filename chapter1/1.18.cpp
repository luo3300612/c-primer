#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int currVal = 0, val = 0;
  if (cin >> currVal) {
    int cnt = 1;
    while (cin >> val) {
      if (val == currVal)
        ++cnt;
      else {
        cout << currVal << " occurs " << cnt << " times" << std::endl;
        currVal = val;
        cnt = 1;
      }
    }
    cout << currVal << " occurs " << cnt << " times " << endl;
  }
  return 0;
}
