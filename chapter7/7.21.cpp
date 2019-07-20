#include <iostream>
using namespace std;

class Sales_data {
  private:
  string bookNo;
  unsigned units_sold;
  double revenue;
  public:
  void combine(const Sales_data &);
  string isbn() { return this->bookNo; }
  Sales_data() : bookNo("000"), units_sold(0), revenue(0) {}
  Sales_data(const string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p) {}
  Sales_data(const string &s) : bookNo(s) {}
  Sales_data(istream &is);
  friend istream& read(istream &,Sales_data &);
  friend ostream& print(ostream &,const Sales_data&);
};

void Sales_data::combine(const Sales_data &s) {
  this->units_sold += s.units_sold;
  this->revenue += s.revenue;
}

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

ostream &print(ostream &os,const Sales_data &s) {
  os << "BookNo:" << s.bookNo << "units_sold:" << s.units_sold
     << "revenue:" << s.revenue;
  return os;
}

int main() {
  Sales_data total(cin);
  if (cin) {
    while (cin) {
      Sales_data trans(cin);
      if (total.isbn() == trans.isbn()) {
        total.combine(trans);
      } else {
        print(cout, total) << endl;
        total = trans;
      }
    }
    print(cout, total) << endl;
  } else {
    cerr << "No data?!" << endl;
  }
}