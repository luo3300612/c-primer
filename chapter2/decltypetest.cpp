#include<iostream>
using namespace std;

char f(int a){
    while(true){
        
    }
    return 'c';
}

int main(int argc, char const *argv[])
{
    decltype(f(1)) a = 'w';
    cout << a << endl;
    return 0;
}
