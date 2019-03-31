#include<iostream>
using namespace std;

int main(){
  int a1,a2;
  cout << "please enter two number a1,a2 s.t a1<a2" << endl;
  cin >> a1 >> a2;
  while(a1<=a2){
    cout << a1<<endl;;
    a1++;
  }
  return 0;
}