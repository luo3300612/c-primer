#include <iostream>
using namespace std;

int abs(int n){
  return (n>0?n:-n);
}
int main(int argc, char const *argv[]) {
  int a;
  while (cin >> a) {
    cout << abs(a) << endl;
  }
  return 0;
}
