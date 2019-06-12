#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
  string text = "asdasadawdwa ddwqeqw qweweq aq";
  for(auto it=text.begin();it!=text.end() && *it!=' ';++it){
    cout << (char)toupper(*it);
  }
  return 0;

}
