#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int score;
  while(cin>>score){
    if(score>90) cout << "A" << endl;
    else if(score>80) cout << "B" << endl;
    else cout << "C" << endl;
  }
  return 0;
}
