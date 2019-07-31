#include<iostream>
using namespace std;

istream& read(istream& is){
  int a;
  while(is>>a){}
  is.clear();
  is.ignore(100,'\n');
  return is;
}

int main(int argc, char const *argv[])
{
  read(cin);
  cout << cin.good() << endl;  
  return 0;
}
