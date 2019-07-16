#include <iostream>
#include <vector>
using namespace std;

void recur_output(vector<string> &v, int index) {
  cout << v[index] << endl;
  if (index != v.size() - 1) {
    recur_output(v, index + 1);
  }
}

int main(int argc, char const *argv[]) {
  vector<string> a = {"sdad", "asdad", "asdasdqwqww", "qqqqqq"};
  recur_output(a, 0);
  /* code */
  return 0;
}
