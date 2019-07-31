#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  ifstream in("./text.txt");
  vector<string> v;
  string s;
  while (in>>s) {
    v.push_back(s);
  }
  for (auto str : v) {
    cout << str << endl;
  }
}