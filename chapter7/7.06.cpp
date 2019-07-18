#include <iostream>
using namespace std;

struct Sales_data {
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
  void combine(const Sales_data &);
  string isbn() { return this->bookNo; }
};

bool read(Sales_data &d) {
  cout << "input book number:" << endl;
  if (!(cin >> d.bookNo))
    return false;
  cout << "input units sold:" << endl;
  if (!(cin >> d.units_sold))
    return false;
  cout << "input revenue:" << endl;
  if (!(cin >> d.revenue))
    return false;
  return true;
}

void Sales_data::combine(const Sales_data &trans) {
  this->units_sold += trans.units_sold;
  this->revenue += trans.revenue;
}

void print(Sales_data &total) {
  cout << "Book Num: " << total.bookNo << ", sold: " << total.units_sold
       << ", revenue:" << total.revenue << endl;
}

Sales_data add(const Sales_data &a1,const Sales_data &a2){
  Sales_data res= a1;
  res.combine(a2);
  return a1;
}

int main(int argc, char const *argv[]) {
  Sales_data total;
  if (read(total)) {
    Sales_data trans;
    while (read(trans)) {
      if (total.bookNo == trans.bookNo) {
        total.combine(trans);
      } else {
        print(total);
        total = trans;
      }
    }
    print(total);
  } else {
    cerr << "No data?1" << endl;
  }
  return 0;
}
