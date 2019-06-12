#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> v1;
  vector<int> v2(10);
  vector<int> v3(10, 42);
  vector<int> v4{10};
  vector<int> v5{10, 42};
  vector<string> v6{10};
  vector<string> v7{10, "hi"};

  for (auto i = v1.begin(); i != v1.end(); i++) {
    cout << *i << endl;
  }
  for (auto i = v2.begin(); i != v2.end(); i++) {
    cout << *i << endl;
  }
  for (auto i = v3.begin(); i != v3.end(); i++) {
    cout << *i << endl;
  }
  for (auto i = v4.begin(); i != v4.end(); i++) {
    cout << *i << endl;
  }
  for (auto i = v5.begin(); i != v5.end(); i++) {
    cout << *i << endl;
  }
  for (auto i = v6.begin(); i != v6.end(); i++) {
    cout << *i << endl;
  }
  for (auto i = v7.begin(); i != v7.end(); i++) {
    cout << *i << endl;
  }

  return 0;
}
