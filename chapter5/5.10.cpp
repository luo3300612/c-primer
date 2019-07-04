#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  char a;
  int sum = 0;
  while(cin>>a){
    if(a=='a'||a=='A') ++sum;
    if(a=='e'||a=='E') ++sum;
    if(a=='i'||a=='I') ++sum;
    if(a=='o'||a=='O') ++sum;
    if(a=='u'||a=='U') ++sum;
  }
  cout << sum;
  return 0;
}
