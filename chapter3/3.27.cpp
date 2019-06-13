#include<iostream>

using namespace std;
int k(){
  return 5;
}
int main(int argc, char const *argv[])
{
  unsigned a = 100;
  int b[a];
  int c[k()] = {1,2,3};
  for(auto cs:c){
    cout << cs;
  }
  return 0;
}
//对对对错