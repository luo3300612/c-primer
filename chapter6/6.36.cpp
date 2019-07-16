#include<iostream>
using namespace std;

string a[] = {"as","as","wq","1","w","wq","7","8","9","10"};

string (*foo1(int i))[10]{
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
