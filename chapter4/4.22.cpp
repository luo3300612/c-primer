#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int grade;
  while(cin>>grade){
    string out = (grade>90)?"优":(grade>80)?"良":(grade>70)?"中等":"合格";
    cout << out << endl;
  }
  return 0;
}
