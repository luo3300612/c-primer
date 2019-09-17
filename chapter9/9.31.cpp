#include<list>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  list<int> li = {0,1,2,3,4,5,6,7,8,9};
  auto iter = li.begin();
  while(iter!=li.end()){
    if(*iter % 2){
      iter = li.insert(iter,*iter);
      ++iter; // 无法进行iter+=2
      ++iter;
    }else{
      iter = li.erase(iter);
    }
  }
  for(auto i:li){
    cout << i << endl;
  }
}

//+=2的问题