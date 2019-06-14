#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
  int a[] = {1,23,4,5,6,4};
  vector<int> b(begin(a),end(a));
  for(auto i:b){
    cout << i<< endl;
  }
  return 0;
}
