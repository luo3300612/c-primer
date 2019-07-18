#include <iostream>
using namespace std;

struct Sales_data {
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

bool read(Sales_data &d) {
  cout << "input book number:" << endl;
  if (!(cin >> d.bookNo)) return false;
  cout << "input units sold:" << endl;
  if(!(cin>>d.units_sold)) return false;
  cout << "input revenue:" << endl;
  if(!(cin>>d.revenue)) return false;
  return true;
}

void combine(Sales_data &total, Sales_data &trans) {
  total.units_sold += trans.units_sold;
  total.revenue += trans.revenue;
}

void print(Sales_data &total) {
  cout << "Book Num: " << total.bookNo << ", sold: " << total.units_sold
       << ", revenue:" << total.revenue << endl;
}

int main(int argc, char const *argv[]) {
  Sales_data total;
  if (read(total)) {
    Sales_data trans;
    while (read(trans)) {
      if(total.bookNo == trans.bookNo){
        combine(total, trans);
      }
      else{
        print(total);
        total = trans;
      }
    }
    print(total);
  }
  else{
    cerr << "No data?1" << endl;
  }
  return 0;
}
