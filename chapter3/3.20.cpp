#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
  int a;
  vector<int> numbers;
  while(cin>>a){
    numbers.push_back(a);
  }
  for(decltype(numbers.size()) i =0;i<numbers.size()-1;i++){
    cout << numbers[i] + numbers[i+1] << endl;
  }
  for(int i = 0;i<numbers.size();i++){
    cout << numbers[i] + numbers[numbers.size()-1-i] << endl;
  }
  return 0;
}
