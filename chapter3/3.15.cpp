#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  string n;
  vector<string> vec;
  while (cin >> n) {
    if(n=="q"){
      break;
    }
    vec.push_back(n);
  }
  for (auto c:vec) {
    cout << c << endl;
  }
  return 0;
}
