#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int a,b;
  while(cin>>a>>b){
    try{
      if(b==0){
        throw runtime_error("divide 0");
      }
      cout << a / b << endl;
    }
    catch(runtime_error err){
      cout << err.what()<<endl;
      cout << "re input?(y/n)";
      char ch;
      cin >> ch;
      if(ch=='y'){
        continue;
      }
      else{
        break;
      }
    }
  }
  return 0;
}
