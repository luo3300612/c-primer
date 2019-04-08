#include <iostream>
using namespace std;

int global_int;
string global_string;

int main(int argc, char const *argv[]) {
  int local_int;
  string local_string;

  cout << local_int << endl;
  cout << global_int << endl;
  cout << local_string << endl;
  cout << global_string << endl;

  return 0;
}
