#include<string>
#include<iostream>

using namespace std;

void myreplace(string& s,string& oldVal,string& newVal){
  int len = oldVal.size();
  for(int i = 0;i<s.size()-len+1;i++){
    if(s.substr(i,len)==oldVal){
      cout << i<<" success"<< endl;
      s.replace(i,len,newVal);
      i = i+len - 1;
    }
    cout << i << endl;
  }
}

int main(int argc, char const *argv[]) {
  string s = "though you are though but I through and through and though";
  string oldVal = "though";
  string newVal = "tho";
  myreplace(s,oldVal,newVal);
  cout << s << endl;
}