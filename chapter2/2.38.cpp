//对顶层const的处理不同
/*
//一样的例子
int a = 10;
auto b = a;
decltype(a) c = a;

//不一样的例子
const int a = 10;
auto b = a;
decltype(a) c = a;


*/