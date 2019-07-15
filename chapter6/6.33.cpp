#include<iostream>
#include<vector>
using namespace std;

void recur_output(const vector<string> &v,int index){
  cout << v[index] << endl;
  if(index!=v.size()-1){
    recur_output(v,index+1);
  }
}

int main(int argc, char const *argv[])
{
  recur_output({"sdad","asdad","asdasdqwqww","qqqqqq"},0);
  /* code */
  return 0;
}
