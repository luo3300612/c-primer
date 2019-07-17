#include<iostream>
#include<vector>
using namespace std;

using PF = int (*)(int,int);

int foo(int a, int b){
  return a+b;
}

int main(int argc, char const *argv[])
{
  vector<PF> v = {foo,foo,foo};
  for(auto i:v){
    cout << i << endl;
  }
  return 0;
}
