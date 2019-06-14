#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
  int a[5];
  vector<int> b = {1,2,3,4,5};
  for(int i = 0;i<5;i++){
    a[i] = b[i];
  }
  for(auto i:a){
    cout << i << endl;
  }
  return 0;
}
