#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> a = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
  vector<int> b(10, 42); // 更好
  vector<int> c;
  for(int i =0;i<10;i++){
    c.push_back(42);
  }
  return 0;
}
