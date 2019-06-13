#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int a[10] = {2, 2, 2, 2, 2, 2};
  for (int i = 0; i < 6; i++) {
    *(a+i)= 1;
  }
  for(auto as:a){
    cout << as << endl;
  }
  return 0;
}
