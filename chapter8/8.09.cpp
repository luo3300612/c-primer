#include <iostream>
#include<sstream>
using namespace std;

istream &read(istream &is) {
  string a;
  while (is >> a) {
    cout << a << endl;
  }
  is.clear();
  return is;
}

int main(int argc, char const *argv[]) {
  istringstream in("asdasda qweqwe eqwe asdd");
  read(in);
  cout << cin.good() << endl;
  return 0;
}
