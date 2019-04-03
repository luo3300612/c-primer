#include "Sales_item.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  Sales_item item,sumItem;
  int count = 1;
  if(cin>>item){
    sumItem = item;
    while(cin>>item){
      if(item.isbn()==sumItem.isbn()){
        count++;
      }
      else{
        cout << sumItem.isbn() << "  " << count << endl;
        count = 1;
        sumItem = item;
      }
    }
    cout << sumItem.isbn() << "  " << count << endl;
  }
  return 0;
}
