#include<iostream>
#include<deque>
using namespace std;

int main(int argc, char const *argv[]) {
  deque<string> q;
  string s;
  while(cin>>s){
    q.push_back(s);
  }
  for(auto it = q.cbegin();it!=q.cend();++it){
    cout << *it << " ";
  }
}