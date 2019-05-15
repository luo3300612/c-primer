#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int i = 0, &r = i;
    auto a = r;
    
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    //auto d = &i;
    //auto e = &ci;

    //auto &g = ci;
    return 0;
}
