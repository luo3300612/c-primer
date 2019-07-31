#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct PersonInfo{
  string name;
  vector<string> phones;
};

int main(int argc, char const *argv[]){
  ifstream in("./phones.txt");
  string line,word;
  vector<PersonInfo> people;
  while(getline(in,line)){
    PersonInfo info;
    istringstream record(line);
    record >> info.name;
    while(record >> word){
      info.phones.push_back(word);
    }
    people.push_back(info);
  }
}