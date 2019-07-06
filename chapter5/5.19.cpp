#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  string s1,s2;
  cin >> s1 >> s2;
  do{
  cout << ((s1.size()<s2.size())?s1:s2);
  }while(cin>>s1>>s2);
  return 0;
}
