#include<iostream>
#include<vector>
using namespace std;

bool find_num(vector<int>::iterator begin,vector<int>::iterator end,int n){
  while(begin!=end){
    if(*begin==n){
      return true;
    }
    begin++;
  }
  return false;
}

int main(int argc, char const *argv[]){
  vector<int> v = {1,2,3,342,5,235,23,536,46,34,5,2345,34,5,2};
  cout << find_num(v.begin(), v.end(), 52222) << endl;
}