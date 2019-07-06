#include"Chapter6.h"
int fact(int n){
  int s = 1;
  while(n>1){
    s*=n;
    --n;
  }
  return s;
}