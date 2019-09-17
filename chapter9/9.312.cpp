#include<forward_list>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  forward_list<int> li = {0,1,2,3,4,5,6,7,8,9};
  auto prev = li.before_begin();
  auto curr = li.begin();
  while(curr!=li.end()){
    if(*curr % 2){
      curr = li.insert_after(prev,*curr);
      ++prev;
      ++prev;
      ++curr;
      ++curr;
    }else{
      curr = li.erase_after(prev);
    }
  }
  for(auto i:li){
    cout << i << endl;
  }
}

//list 的insert和erase方法都返回指向当前元素的iterator，且不能使用与int的加法