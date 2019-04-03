#include "Sales_item.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  Sales_item item1, sum;
  cin >> item1;
  sum = item1;
  while(cin>>item1){
    sum += item1;
  }
  cout << sum << endl;
  
  return 0;
}
