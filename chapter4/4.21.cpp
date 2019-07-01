#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
  vector<int> vec = {1,2,3,4,5,6,7,8,9};
  for(auto it=vec.begin();it!=vec.end();++it){
    *it = (*it%2==1)?*it*2:*it;
  }
  for(auto i:vec){
    cout << i << endl;
  }
  return 0;
}
