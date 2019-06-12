#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
  vector<int> numbers = {1,2,3,4,5,6,7,8,9,22};
  for(auto i = numbers.begin();i!=numbers.end();++i){
    *i = 2 * (*i);
  }
  for(auto i:numbers){
    cout << i << endl;
  }
  return 0;
}
