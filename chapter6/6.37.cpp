#include<iostream>
using namespace std;

typedef string strArr1[10];
using strArr2 = string[10];

string a[] = {"as","as","wq","1","w","wq","7","8","9","10"};

string (*foo1(int i))[10]{
  return &a;
}

strArr1 *foo2(int i){
  return &a;
}

strArr2 *foo3(int i){
  return &a;
}

auto foo4(int i)->string(*)[10]{
  return &a;
}

decltype(a) *foo5(int i){
  return &a;
}

int main(int argc, char const *argv[])
{
  string (*a)[10] = foo1(1);
  for(auto it:*a){
    cout << it << endl;
  }
  return 0;
}
