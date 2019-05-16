# C++ primer
## Chapter1
### 编译命令
```shell
g++ -o main *.cpp # 生成名为main的可执行文件
g++ *.cpp # 自动生成名为a.out的可执行文件
```
### 查看程序main函数return的结果
UNIX
```shell
echo $?
```
Windows
```shell
echo %ERRORLEVEL%
```
### C++11支持
可能需要指定`-std=c++0x`来打开
### 缓冲刷新
`std::endl`的效果是结束当前行，并将与设备关联的缓冲区（buffer）中的内容刷到设备中，缓冲刷新操作可以保证到目前为止程序所产生的所有输出都真正写入输出流中，而不是仅停留在内存中等待写入流
### istream对象作为条件
```cpp
while(std::cin >> value)
```
`>>` 是一个二元运算符，左侧是istream对象，右侧是输入，运算结果是左侧的istream对象（这使得连续>>成为可能）,上面的代码中，返回的istream对象成为了条件，此时效果是检测流的状态，如果流是有效的，即流未遇到错误，那么检测成功，当遇到**文件结束符**（end-of-file），或遇到一个无效的输入时（例如读入的不是一个value的类型的值），istream对象的状态会变为无效，此时作为条件为假
### 文件结束符
Windows中文件结束符是`Ctrl+Z`然后按回车，UNIX系统中（包括Mac OS X），文件结束符是Ctrl+D
### 头文件的<>和“”
<>包围来自标准库的头文件，""包围不属于标准库的头文件
## Chapter2
### 类型
C++定义了一套包括**算数类型**（arithmetic type）和**空类型**（void）在内的基本数据类型
### 选择类型的建议
* 明确知道不可能为负时，选用无符号类型
* 使用int执行整数运算，实际应用中，short常常太小而long一般和int有一样的尺寸，如果实际值超过了int的范围，选用long long
* 在算数表达式中不要使用char或bool，只有在存放字符或布尔值时才使用它们。因为类型char在一些机器上是有符号的，而在另一些机器上又是无符号的，所以如果使用char进行运算特别容易出现问题。如果需要使用一个不大的整数，那么明确指定它的类型是signed char或者unsigned char
* 执行浮点运算时选用double，因为float常常精度不够且双精度浮点数和单精度浮点数的计算代价相差无几。事实上，对于某些机器来说，双精度的运算甚至比单精度还快。long double提供的精度在一般情况下是没有必要的，况且它带来的运行时消耗也不容忽视。
### 浮点数转化为整数
保留小数点之前，不是四舍五入也不是向下取整
### 含有无符号的表达式
如果表达式中有int和无符号时，int会转化为无符号数
### 长字符串换行
这样的代码是合法的
```c++
cout << "aaaa"
  "bbb" << endl;
```
### 字面值对应类型
一般字面值的类型是能容纳该字面值的最小类型，比如12212121212，就是int、long、long long中能容纳它的最小的类型
### 指定字面值的类型
使用前缀或后缀指定字面值的类型
|前缀|含义|类型|
|---|---|---|
|u|Unicode 16字符|char16_t|
|U|Unicode 32字符|char32_t|
|L|宽字符|wchar_t|
|u8|UTF-8(仅用于字符串字面常量)|char|

整型字面值
|后缀|最小匹配类型|
|---|---|
|u or U|unsigned|
|l or L|long|
|ll or LL|long long|

浮点型字面值
|后缀|最小匹配类型|
|---|---|
|f或F|float|
|l或L|long double|
请尽量使用L作为long的代表，避免l和1的混淆
### 进制
以0开头是八进制数字，以0x或0X开头是16进制

### 初始化和赋值
初始化不是赋值，初始化的含义是创建变量时赋予其一个初始值，而赋值的含义是把对象的当前值擦除而以一个新的值取代

### 列表初始化
四种初始化方法
```cpp
int a = 0;
int a = {0};
int a{0};
int a(0);
```
这种初始化的形式称为列表初始化（list initialization），当使用列表初始化且初始值存在丢失信息的风险时，编译器会报错：
```cpp
long double ld = 3.1415922653;
int a{ld}, b = {ld}; // 错误：转化未执行，因为存在信息丢失的危险
int c(ld), d= ld; // 正确：转换执行，且确实丢失了部分值
```
### 变量声明和定义
变量能且只能被定义一次，但是可以多次声明。如果要在多个文件中使用同一个变量，就必须将声明和定义分离。此时变量的定义必须出现在且只能出现在一个文件中，而其他用到该变量的文件必须对其进行声明
声明变量的方法：
```cpp
extern int i; // 声明
int i; // 定义
```
### c++的静态类型
C++是一种静态类型（statically typed）语言，其含义是在编译阶段检查类型，其中检查类型的过程称为类型检查（type checking）

对象的类型决定了对象所能参与的运算，C++中，编译器负责检查数据类型是否支持要执行的运算，如果视图执行类型不支持的运算，编译器将报错且不会生成可执行文件。

程序越复杂，静态类型检查就越有助于发现问题。然而，前提是编译器必须知道每一个实体对象的类型，这就要求我们在使用某个变量之前必须声明其类型。

### 标识符
c++的标识符由字母数字和下划线组成，其中必须以字母或下划线开头，长度没有限制，但对大小写敏感，用户自定义的标识符中不能连续出现两个下划线（自己试过却可以），不可以使用下划线紧连大写字母开头（自己试过却可以），定义在函数体外的标识符不能以下划线开头（自己试过却可以）

### 变量命名规范
* 体现实际含义
* 一般使用小写字母
* 用户自定义类以大写字母开头
* 如果标识符由多个单词组成，则单词间应有明显区分，如student_loan或studentLoan

### 显式访问全局变量
```cpp
::global_var
```
### 复合类型
#### 引用
引用是一种符合类型，引用即别名
```cpp
int a = 1;
int &b = a;
```
引用只能绑定对象，不可以绑定字面值或表达式，且引用定义时就要绑定，初始化后将一直保持绑定，无法更改
```cpp
int &a = 1; // 错误
int &a; // 错误
```
注意此处的无法更改是指没有办法，如下的语句看似更改了引用
```cpp
int a = 1;
int &b = a;
int c = 2;
b = c;
```
但其实此时应将b看作a的别名，就是将c的值赋给a，而不是更改b的引用到c
#### 指针
指针也是一种复合类型，与引用类似，指针也实现了对其他对象的简介访问。不同之处在于
* 指针是一个对象，引用不是对象，指针允许对指针的赋值和拷贝，且可以指向不同对象
* 指针无需在定义时赋值
```cpp
int *ip1, *ip2;
```
注意：和引用一样，指针的*号写在变量名的前面构成声明符（declarator）

指针存放对象的地址，通过取地址符（&，与引用一样）定义
```cpp
int ival = 42;
int *p = &ival;
```
无论是指针或引用，常情况下应与指向的值类型匹配

通过解引用符（*）获得对象
```cpp
int ival = 42;
int *p = &ival;
cout << *p;
```
可见*和&的不同作用，作为运算符或者定义复合类型的符号

生成空指针的方法
```cpp
int *p1 = nullptr; // 推荐
int *p2 = 0;
int *p3 = NULL; // 尽量避免
```

**可能的情况下，初始化所有指针，否则因为指针未被初始化导致访问不明地址的值的错误很难检测出来,且会出现不可预计的结果**

void*指针可以指向任意类型的对象，但却因为不知道存储的是什么对象的地址而无法操作所指的对象
#### 指向指针的指针
```cpp
int **p;
```
#### 指向指针的引用
```cpp
int i = 42;
int *p;
int *&r = p;
```
从右向左读，右边的最重要
### 常量
```cpp
const int a = 10;
```
常量必须初始化且不可更改

常量引用是可以使用字面值初始化引用的一个例外
```cpp
int i = 42;
const int &r = 42;
```
此时编译器会生成一个temp对象，实际上引用的是该temp对象

允许通过常量引用一个非常量对象，反之则不行，这种行为是合法的，但无法通过引用来更改对象

允许使用指向常量指针来指向一个非常量对象，反之则不行，这也仅仅要求了不可以通过常量指针来更改对象

常量指针
```cpp
int errNumb = 0;
int *const curErr = &errNumb;
```
常量指针与指向常量的指针不同，常量指针意味着不可更改的是指针指向的地址而不是指针指向的常量的值

#### 顶层const和底层const
顶层const就是指针是常量

底层const就是指针指向的是常量
### 常量表达式
constexpr变量，常量表达式就指值不会改变并且在编译过程中就能得到计算结果的表达式，可以将变量声明为constexpr类型来验证变量的值是否是一个常量表达式


### 类型别名
通过以下方法可以定义类型别名
```cpp
typedef double wages; // wages是double的同义词
typedef wages base, *p; // base戳double的同义词，p是double*的同义词
```
新标准的**别名声明（alias declaration）**
```cpp
using SI = Sales_item;
```

使用别名后的一个误区
```cpp
typedef char *pstring;
const pstring cstr = 0;
const char *cstr = 0;
```
第二行和第三行并不一样，前者是指向char的常量指针，后者是指向const char的指针

### auto类型说明符
auto可以让编译器分析变量的类型

### decltype
如果只想得到某个变量的类型，可以通过decltype完成，甚至可以取函数的返回值，这个过程不会实际执行函数
```cpp
char f(int a){
  while(true){
    return 'c';
  }
}

decltype(f(1)) a = 'w';
```

`decltype((变量))`加双层括号的结果永远是引用类型

## 头文件
头文件需要设置保护符
```
#ifndef blabla
#define blabla
...
#endif
```
## 常见错误
### float的字面值
```cpp
cout << 1024f << endl;
```
f直接跟在整数后面，应该改成1024.f
### 指针类型
```cpp
int* a,b;
```
这是合法的写法，但b并非是指针，只是一个int的值
