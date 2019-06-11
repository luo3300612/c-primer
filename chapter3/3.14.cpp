#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
  int n;
  vector<int> vec;
  while(cin>>n){
    vec.push_back(n);
  }
  for(int i=0;i<vec.size();i++){
    cout << vec[i] << endl;
  }
  return 0;
}
