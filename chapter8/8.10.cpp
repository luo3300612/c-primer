#include<sstream>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[]){
  ifstream in_file("text.txt");
  vector<string> v;
  string s;
  while(in_file>>s){
    v.push_back(s);
  }
  for(auto str:v){
    istringstream in(str);
    in>> s;
    cout << s << endl;
  }
}