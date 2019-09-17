#include<vector>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> ve = {1,2,3,4,5,7};
  auto begin = ve.begin();
  while(begin!=ve.end()){
    ++begin;
    ve.insert(begin,42);
    ++begin;
  }
  for(auto i:ve){
    cout << i << endl;
  }
}