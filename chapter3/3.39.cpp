#include<string>
#include<cstring>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  string a = "123";
  string b = "123";
  char aa[] = "123";
  char bb[] = "123";
  if(a==b){
    cout << "eq" << endl;
  }
  if(!strcmp(aa,bb)){
    cout << "eq" << endl;
  }
  return 0;
}
