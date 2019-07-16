#define NDEBUG
#include <iostream>
#include<vector>
#include<cassert>
using namespace std;

void print(vector<int> v, int n) {
  assert(n>0);
  if (n < v.size()) {
    cout << __FILE__ << endl;
    cout << __func__ << endl;
    cout << __LINE__ << endl;
    cout << __TIME__ << endl;
    cout << __DATE__ << endl;
    print(v, n + 1);
  }
}

int main(int argc, char const *argv[])
{
  int N = 10;
  vector<int> v = {1,2,3,4,5,6,7,8,9,10};
  print(v,0);
  return 0;
}
