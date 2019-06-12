#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> numbers;
  int a;
  while (cin >> a) {
    numbers.push_back(a);
  }
  for(auto i=numbers.begin();i!=numbers.end()-1;i++){
    cout << *i + *(i+1) << endl;
  }
  cout << "------" << endl;
  for(auto i=numbers.begin(),j=numbers.end()-1;i<j;i++,j--){
    cout << *i + *j << endl;
  }
  return 0;
}
