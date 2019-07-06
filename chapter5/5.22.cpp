#include<iostream>
using namespace std;

int get_size(){
  return 1;
}

int main(int argc, char const *argv[])
{
  int sz;
  do{
    sz = get_size();
  }while(sz<=0);
  return 0;
}
