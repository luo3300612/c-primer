#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
  vector<int> a = {1,2,3,4,5,6,7,7,8,8};
  vector<int> b = {1,2,3,4,5,6,7};
  bool flag = true;
  for(decltype(b.size()) i=0;i<b.size();++i){
    if(b[i]!=a[i]){
      flag = false;
      break;
    }
  }
  cout << flag;
  return 0;
}
