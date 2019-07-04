#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  char a;
  int sum = 0;
  while(cin>>a){
    if(a=='a') ++sum;
    if(a=='e') ++sum;
    if(a=='i') ++sum;
    if(a=='o') ++sum;
    if(a=='u') ++sum;
  }
  cout << sum;
  return 0;
}
