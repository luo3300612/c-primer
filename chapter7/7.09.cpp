#include <iostream>
using namespace std;

struct Person {
  string name;
  string address;
  string who() const { return this->name; }
  string where() const { return this->address; }
};

istream &read(istream &i,Person &p){
  cout << "input name:" << endl;
  i >> p.name;
  cout << "input address:" << endl;
  i >> p.address;
  return i;
}

ostream &print(ostream &o,const Person &p){
  o << "Name:" << p.name << ", Address:" << p.address << endl;
  return o;
}

int main(int argc, char const *argv[])
{
  Person p;
  read(cin,p);
  print(cout,p);
  return 0;
}
