#include<iostream>
#include<forward_list>

using namespace std;

forward_list<string>::iterator my_insert(forward_list<string> &fl,string &s1,string &s2){
  auto prev = fl.before_begin();
  auto curr = fl.begin();
  while(curr!=fl.end()){
    if(*curr==s1){
      curr = fl.insert_after(curr,s2);
      return curr;
    }
    ++curr;
    ++prev;
  }
  curr = fl.insert_after(prev,s2);
  return curr;
}

int main(int argc, char const *argv[]) {
  forward_list<string> fl = {"a","b","e","d"};
  string s1 = "b";
  string s2 = "c";
  my_insert(fl,s1,s2);
  for(auto i:fl){
    cout << i << endl;
  }
  string ss1 = "q";
  string ss2 = "p";
  my_insert(fl,ss1,ss2);
  for (auto i : fl) {
    cout << i << endl;
  }
}