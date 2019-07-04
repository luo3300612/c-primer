#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int sum =0,val=1;
  while(val<=10)sum+=val,++val;
  cout << sum << endl;
  return 0;
}
