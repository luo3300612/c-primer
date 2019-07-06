#include<iostream>
using namespace std;

int count(){
  static int a = 0;
  return a++;
}

int main(int argc, char const *argv[])
{
  cout << count() << endl;
  cout << count() << endl;
  cout << count() << endl;
  cout << count() << endl;
  cout << count() << endl;

  return 0;
}
