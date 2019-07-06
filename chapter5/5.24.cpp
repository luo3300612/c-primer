#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int a,b;
  cin >> a >> b;
  if(b==0){
    throw runtime_error("divide 0");
  }
  cout << a / b << endl;
  return 0;
}
