#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  string s,last_s;
  bool flag = false;
  int count=0;
  int max_count = 0;
  while(cin>>s){
    if(s==last_s){
      flag = true;
      ++count;
    }
    else{
      flag = false;
      max_count = count>max_count?count:max_count;
      count = 0;
    }
    last_s = s;
  }
  cout << max_count + 1 << endl;
  return 0;
}
