#include<string>
#include<iostream>
using namespace std;

void concat(string &name,string &prefix, string &postfix){
  name.insert(0,prefix);
  name.append(postfix);
}

int main(int argc, char const *argv[]) {
  string name = "Peter";
  string prefix = "Mr ";
  string postfix = " I";
  concat(name,prefix,postfix);
  cout << name << endl;
}