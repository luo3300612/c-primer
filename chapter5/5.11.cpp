#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int vowelCnt = 0;
  int space = 0;
  int shiftline=0;
  int table = 0;
  char ch;
  bool flag;
  while(cin.get(ch)){
    switch(ch) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      ++vowelCnt;
      break;
    case '\t':
      ++table;
      break;
    case '\n':
      ++shiftline;
      break;
    case ' ':
      ++space;
      break;
    case 'q':
      flag = 1;
      break;
    default:
      break;
    }
    if(flag) break;
  }
  
  cout << "vowel:" << vowelCnt << endl;
  cout << "table:" << table << endl;
  cout << "shiftline:" << shiftline << endl;
  cout << "space:" << space << endl;
  return 0;
}
