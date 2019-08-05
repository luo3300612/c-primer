#include <deque>
#include <iostream>
#include <list>
using namespace std;

int main(int argc, char const *argv[]) {
  list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  deque<int> q1, q2;
  for (auto i : l) {
    if (i%2==0)
      q1.push_back(i);
    else
      q2.push_back(i);
  }
  cout << "q1" << endl;
  for (auto i : q1) {
    cout << i << " ";
  }
  cout << endl;
  cout << "q2" << endl;
  for (auto i : q2) {
    cout << i << " ";
  }
}