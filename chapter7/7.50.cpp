#include <iostream>
using namespace std;

class Person {
private:
  string name = "UNKNOWN";
  string address = "UNKNOWN";

public:
  string who() const { return this->name; }
  string where() const { return this->address; }
  Person() = default;
  explicit Person(const string &n) : name(n) {}
  Person(const string &n, const string &a) : name(n), address(a) {}
  Person(istream &);
  friend istream &read(istream &, Person &);
  friend ostream &print(ostream &, const Person &);
};

istream &read(istream &is, Person &p) {
  cout << "input name:" << endl;
  is >> p.name;
  cout << "input address:" << endl;
  is >> p.address;
  return is;
}

ostream &print(ostream &o, const Person &p) {
  o << "Name:" << p.name << ", Address:" << p.address << endl;
  return o;
}

Person::Person(istream &is) { read(is, *this); }

int main(int argc, char const *argv[]) {
  Person p1(cin);
  Person p2;
  Person p3("bob", "beijing");
  Person p4("peter");
  print(cout, p1);
  print(cout, p2);
  print(cout, p3);
  print(cout, p4);
}
