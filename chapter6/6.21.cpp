#include<iostream>
using namespace std;
int compare(const int a,const int *b){
  return (a>*b?a:*b);
}

int main(int argc, char const *argv[])
{
  int a = 1,b = 2;
  cout << compare(a,&b);
  return 0;
}
