#include<iostream>
using namespace std;

void print(int a,const int *beg,const int *end){
  cout << a;
  while(beg!=end){
    cout << *beg++ << endl;
  }
}

int main(int argc, char const *argv[])
{
  int i = 0, j[2] = {0,1};
  print(i,begin(j),end(j));
  return 0;
}
