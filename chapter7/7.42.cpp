#include <iostream>
using namespace std;

class Date {
  int year;
  int month;
  int day;

  Date(int y, int m, int d) : year(y), month(m), day(d) {}
  Date() : Date(0, 0, 0) {}
  Date(istream &is) : Date() {
    cout << "year:";
    is >> year;
    cout << "month:";
    is >> month;
    cout << "day:";
    is >> day;
  }
};

int main(int argc, char const *argv[]) { return 0; }