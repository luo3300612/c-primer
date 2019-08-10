#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  vector<int> v(begin(ia), end(ia));
  list<int> l(begin(ia), end(ia));
  auto it = v.begin();
  while (it != v.end()) {
    if (*it % 2 == 0)
      it = v.erase(it);
    else
      ++it;
  }
  auto itl = l.begin();
  while(itl!=l.end()){
    if(*itl %2 == 1) itl = l.erase(itl);
    else ++itl;
  }
  for(auto i:v){
    cout << i << endl;
  }
  for(auto i:l){
    cout << i << endl;
  }
}