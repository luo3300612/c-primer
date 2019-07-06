#include<iostream>
using namespace std;

int fact(int n){
  int s = 1;
  if(n<=1){
    return s;
  }
  while(n>1){
    s*=n;
    n--;
  }
  return s;
}

int main(int argc, char const *argv[])
{
  int a;
  while(cin >>a){
    cout << fact(a) <<endl;
  }
  return 0;
}
