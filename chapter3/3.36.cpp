#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
  int a[]= {1,2,3,4,5};
  int b[] = {1,2,3,4,5};
  for(int i =0;i<5;i++){
    if(a[i]!=b[i]){
      cout << "neq" << endl;
      break;
    }
    if(i==4){
      cout << "eq"  << endl;
    }
  }
  vector<int> aa = {1,2,3,4,5};
  vector<int> bb = {1,2,3,4,5};
  if (aa==bb){
    cout << "eq" <<endl;
  }
  else{
    cout<<"neq"<<endl;
  }
  return 0;
}
