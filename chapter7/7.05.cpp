#include <iostream>
using namespace std;

struct Person {
  string name;
  string address;
  string who() const { return this->name; }
  string where() const { return this->address; }
}