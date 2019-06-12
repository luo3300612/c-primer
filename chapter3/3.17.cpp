#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
  string word;
  vector<string> words;
  while(cin>>word){
    if(word=="q"){
      break;
    }
    words.push_back(word);
  }

  for(auto &word:words){
    for(auto &c:word){
      c = toupper(c);
    }
    cout << word << endl;
  }
  return 0;
}
