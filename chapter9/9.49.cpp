#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(int argc, char const *argv[]) {
  string ascender = "bdfhijklt";
  string descender = "gjpqy";
  string s;

  string max_s;
  ifstream in("./words.txt");
  int max_len = 0;
  if(in){
    while(in>>s){
      if(s.find_first_of(ascender) ==string::npos&&s.find_first_of(descender)==string::npos){
        int len = s.size();
        if(len>max_len){
          max_len = len;
          max_s = s;
        }
      }
    }
    cout << max_s << endl;
  }
  else{
    cerr << "couldn't open" << endl;
    return -1;
  }

}
