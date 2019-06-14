#include<cstring>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  char a[] = "12345";
  char b[] = "67890";
  char c[20];
  strcpy(c,a);
  strcat(c,b);
  cout << c << endl;
  return 0;
}
