#include <iostream>
using namespace std;

class Sales_data;

istream &read(istream &is, Sales_data &s);


struct Sales_data {
  string bookNo;
  unsigned units_sold;
  double revenue;
  void combine(const Sales_data &);
  string isbn() { return bookNo; }

  Sales_data(const string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p) {}
  Sales_data() : Sales_data("", 0, 0) {}
  Sales_data(const string &s) : Sales_data(s, 0, 0.0) {}
  Sales_data(istream &is) : Sales_data() { read(is, *this); }
  inline double avg_price() { return revenue / units_sold; }
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

void Sales_data::combine(const Sales_data &s) {
  this->units_sold += s.units_sold;
  this->revenue += s.revenue;
}

ostream &print(ostream &os, Sales_data &s) {
  os << "BookNo:" << s.bookNo << "units_sold:" << s.units_sold
     << "revenue:" << s.revenue;
  return os;
}

int main() {
  Sales_data total(cin);
  Sales_data s1("111",22,22);
  Sales_data s2("2322");
  Sales_data s3;
  print(cout,total) << endl;
  print(cout,s1) << endl;
  print(cout,s2) << endl;
  print(cout,s3) << endl;
}