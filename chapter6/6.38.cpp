#include<iostream>
using namespace std;

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

decltype(odd) &arrPtr(int i){
  return (i%2)? odd:even;
}

int main(int argc, char const *argv[])
{
  int (&r)[5] = arrPtr(5);
  for(auto it:r){
    cout << it << endl;
  }
  return 0;
}
