#include <list>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  list<string> q;
  string s;
  while (cin >> s) {
    q.push_back(s);
  }
  for (auto it = q.cbegin(); it != q.cend(); ++it) {
    cout << *it << " ";
  }
}