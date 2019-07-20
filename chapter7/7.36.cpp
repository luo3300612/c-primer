#include <iostream>
using namespace std;

struct X{
  X(int i,int j):base(i),rem(base %j){}
  int rem,base;
};

int main(int argc, char const *argv[]){
  X x(2,3);
  cout << x.rem << " "<< x.base;
  return 0;
}