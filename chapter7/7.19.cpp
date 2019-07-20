#include <iostream>
using namespace std;

struct Person {
  private:
  string name = "UNKNOWN";
  string address = "UNKNOWN";
  public:
  string who() const { return this->name; }
  string where() const { return this->address; }
  Person() = default;
  Person(const string &n) : name(n) {}
  Person(const string &n, const string &a) : name(n), address(a) {}
  Person(istream &);
};
