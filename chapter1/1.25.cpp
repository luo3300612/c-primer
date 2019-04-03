#include "Sales_item.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  Sales_item item, sumItem;
  if (cin >> item) {
    sumItem = item;
    while (cin >> item) {
      if (item.isbn() == sumItem.isbn()) {
        sumItem += item;
      } else {
        cout << sumItem << endl;
        sumItem = item;
      }
    }
    cout << sumItem << endl;
  }
  return 0;
}
