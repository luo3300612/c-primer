#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int a[] = {1,2,34,6,6,7};
  cout << sizeof a << endl;
  int *b=a+10;
  cout << sizeof *b << endl;
  return 0;
}
