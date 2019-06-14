#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int a[2][2] = {1,4,5,6};
  for(int (&b)[2]:a){
    for(int c:b){
      cout << c;
    }
  }
  cout << endl;

  for(int i =0;i<2;i++){
    for(int j=0;j<2;j++){
      cout << a[i][j];
    }
  }
  cout << endl;
  

  for (int (*i)[2] = a; i != a+2; i++) {
    for (int* j = *i; j != *i+2; j++) {
      cout << *j;
    }
  }
  // return 0;
}
