//死循环
#include<vector>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> v = {1,2,3,4,5,6};
  auto iter = v.begin();
  while(iter!=v.end()){
    if(*iter %2)
      iter = v.insert(iter,*iter);
    ++iter;
  }
}