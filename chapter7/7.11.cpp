#include <iostream>
using namespace std;

struct Sales_data {
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
  void combine(const Sales_data &);
  string isbn() { return this->bookNo; }
  Sales_data() = default;
  Sales_data(const string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p) {}
  Sales_data(const string &s) : bookNo(s) {}
  Sales_data(istream &is);
};

istream &read(istream &is, Sales_data &s) {
  cout << "input bookNo" << endl;
  is >> s.bookNo;
  cout << "input units_sold" << endl;
  is >> s.units_sold;
  cout << "input revenue" << endl;
  is >> s.revenue;
  return is;
}

Sales_data::Sales_data(istream &is) { read(is, *this); }

ostream &print(ostream &os, Sales_data &s) {
  os << "BookNo:" << s.bookNo << "units_sold:" << s.units_sold
     << "revenue:" << s.revenue << endl;
  return os;
}

int main() {
  Sales_data s1("big", 1, 100);
  Sales_data s2("small");
  Sales_data s3(cin);
  print(cout, s1);
  print(cout, s2);
  print(cout, s3);
}