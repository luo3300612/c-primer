#include <iostream>
#include <string>

using namespace std;

struct Sales_data {
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main(int argc, char const *argv[]) {
  Sales_data chilken_leg1;
  Sales_data chilken_leg2;

  cout << "1" << endl;
  cout << "no units_sold revenue" << endl;
  cin >> chilken_leg1.bookNo >> chilken_leg1.units_sold >> chilken_leg1.revenue;
  cout << "2" << endl;
  cout << "no units_sold revenue" << endl;
  cin >> chilken_leg2.bookNo >> chilken_leg2.units_sold >> chilken_leg2.revenue;

  if (chilken_leg1.bookNo == chilken_leg2.bookNo) {
    Sales_data chilken_leg3;
    chilken_leg3.units_sold = chilken_leg1.units_sold + chilken_leg2.units_sold;
    chilken_leg3.bookNo = chilken_leg1.bookNo;
    chilken_leg3.revenue = chilken_leg1.revenue + chilken_leg2.revenue;
    cout << chilken_leg3.bookNo << " " << chilken_leg3.units_sold << " " << chilken_leg3.revenue << endl;
  }
  else{
    cout << "can't add" << endl;
  }


  return 0;
}
