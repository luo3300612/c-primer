#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int score;
  while(cin>>score){
    string out = score>90?"A":score>80?"B":"C";
    cout << out << endl;
  }
  return 0;
}
