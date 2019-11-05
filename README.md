# C++ primer
## Trick
* 使用迭代器
* 能使用const使用const，比如迭代器cbegin这样的
* 对于复杂的结构体或类，能用引用就用引用
* 常量引用参数比单纯引用更好，因为能接受常量输入或const参数
* 打开文件记得检查是否打开成功
* 换行 \

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

## Chapter3
### 命名空间的using声明
通过使用using声明，即可避免反复输入std::
```cpp
using std::cin; using std::cout;
```
声明以分号结尾，一行可以写多个

### string
string是可变长的字符序列，使用方法如下
```cpp
#include<string>
using std::string
```
#### 初始化
```cpp
string s1 = "aanb";
string s2(10, 'c'); // 'cccccccccc' 
```
直接初始化和拷贝初始化
```cpp
string s1 = "aabn"; // 拷贝初始化
string s2("aabn"); // 直接初始化
```
对上面的例子来说是一样的，但当使用多个值来初始化时
```cpp
string s1 = string(3,'c'); // 直接初始化
string s2(3,'c'); // 拷贝初始化
```
因为c++中使用等号初始化是拷贝初始化的方式，相比而言，使用多个变量初始化的时候，推荐还是使用直接初始化方法

#### 读写
string接受输入时会自动忽略开头的空白（空格、换行、制表符等），读到下一个空白的位置

可以使用getline读取一整行，读到换行符结束，并丢弃掉该换行符
```cpp
string s;
getline(cin,s); //读取一整行
```
#### empty size
string.empty()和string.size()
注意string.size()返回的是一个string::size_type的无符号数，这意味着不能随意对这个数和int型数进行计算
#### string.func()
书p82
#### 处理每个字符
```cpp
string s = "asd";
for(auto &c:){
  c = 'w';
}
```
### vector
#### 声明
#include<vector>
using std::vector;
#### 初始化
```cpp
vector<T> a(n,val);
vector<T> a = {a,b,c};
```
花括号和圆括号
```cpp
vecotr<int> v1(10); // 10个元素，每个都是默认值
vector<int> v2{10}; // 1个10
```
#### 添加元素
```cpp
vector.push_back
```
#### 成员函数
```cpp
vector.size() // vector 元素个数
vector.empty() // vector 是否为空
```
#### 效率
vector能高效增长，因此定义vector时预先设置其大小没有太多必要，且这样做有时效果可能适得其反
#### 索引
可以通过索引访问元素，但不能用索引添加元素，只能用索引修改元素
#### auto
使用auto来遍历vector也是很方便的
```cpp
vector<string> s = {........};
for(auto c:s){
  cout << c;  
}
```
### 迭代器
* c++迭代器和python迭代器有什么区别？
  c++的迭代器是类似一个指针的东西，迭代器指向元素，且可以随意更改迭代器指向的位置，python的迭代器是实现了__iter__的类，且python的迭代器不可以随意更改指向元素的位置
* python的可迭代对象和迭代器有什么区别？
  回去查书...
* 有了范围for之后，还要迭代器干嘛？
  范围for针对当前的元素，丧失了下标索引的灵活性，而迭代器则保持了这个灵活性，在迭代器中的不同位置元素需要交互时，使用迭代器或者索引更好，仅仅对单个元素进行操作时，使用范围for更好

标准库定义了很多容器，包括string，所有标准库的容器都可以使用迭代器，但其中少数才同时支持下标运算符

#### 使用迭代器
通过.begin和.end来使用迭代器
```cpp
string s = "12334";
for(auto it=s.begin();it!=s.end();++it){
  *it = toupper(*t);
}
```
迭代器类似指针，需解引用来访问元素

#### 泛型编程
c++中循环一般使用!=而非<，这是因为这样的判断对所有标准库容器都有效

#### 常量迭代器
.cbegin和.cend返回的是常量迭代器，其中的元素不可变

#### 箭头
为了访问迭代器指向的元素，需要解引用，同时，有时我们要访问指向对象的成员函数，就会这样写
```cpp
(*p).empty();
```
这样十分麻烦，c++中的箭头就是一种替代写法，它同时进行解引用和成员访问
```cpp
p->empty();
```
#### 迭代器运算
迭代器支持与常数的+ - 运算，以及迭代器之间的减法运算

### 数组
数组类似vector，不同的是不能向数组中任意添加元素，必须声明数组大小，但也可以通过列表初始化省略声明
```cpp
char a[10];
int b[] = {1,23,4,5};
char c[3] = "AK"; // c[2]是'\0'
```
#### 指针和数组
使用数组的时候编译器会将其变成一个指针

推导类型不同
```cpp
int a[10];
auto b = a; // b是指针
decltype(a) c; // c是数组 
```

#### 指针也是迭代器
因为指针不是类，可以通过begin(),end()函数获得迭代器
```cpp
for(auto it=begin(a);it!=end(i);it++){
  // do something
}
```

#### 下标
数组的下标可以是负值相当于指针向前移位

### C风格字符串
c风格字符串包括在cstring头文件中，是string.h的c++版本，字符串在字符数组中，最后一个元素是'\0'，一般来说，使用string比使用c风格字符串更简洁高效

### 与旧代码的接口
允许用以空字符结束的字符数组来初始化string，反过来不行，但可以使用s.c_str()将字符串转化为c风格字符串

可以同数组来初始化vector对象
```cpp
int a[] = {1,2,3};
vector<int> ivec(begin(a),end(a));
```

**使用指针和数据容易出错，因为它们属于底层操作，现代c++程序应当尽量使用vector和迭代器，尽量使用string**

### 多维数组
多维数组初始化
```cpp
int a[2][2] = {
  {1,2},
  {3,4}
};
int b[2][2] = {1,2,3,4};
```

使用范围for来遍历数组
```
for(auto &row:a)
  for(auto &cal:row){
    //do something
  }
```
这是针对需要改变数组元素的范围for，使用了引用，但实际上，还有别的原因驱使我们使用引用，这是为了避免数组被自动转化为指针，如果不使用引用，程序无法通过编译

**如果对多维数组使用范围for，除了最内层的训练，其他所有循环都需要使用引用类型**

```cpp
int *p[4]; // 数组的指针
int (*p)[4]; // 指针的数组
```

新标准类别声明
```
using int_array = int[4];
```

## 表达式
### 基础
#### 左值和右值
c语言中，两者区别简记为：左值可以位于赋值语句的左侧，右值则不能
c++中：当一个对象被用作右值的时候，用的是对象的值（内容）；当对象被用作左值的时候，用的是对象的身份（在内存中的位置）

decltype对左值和右值的结果都不同，如果表达式的求值结果是左值，decltype则得到一个引用类型，比如假设p类型是int\*，因为解引用得到的是左值，因此decltype(*p)的结果是int &，因为取地址算法生成右值所以decltype(&p)的结果是int\*\*？？（是不是反了？？）

赋值运算符左侧必须是左值，有侧可左可右

#### 求值顺序
c++大多数情况没有规定二元运算符的求值顺序比如
```cpp
int i = f1() * f2();
```
f1和f2都会在乘法之前计算，但是具体计算顺序是未知的，这也引入一个问题
```cpp
int i = 0;
cout << i << " " << ++i << endl;
```
上式也是未定义行为

但c++中有四种运算符明确规定了运算对象的求值顺序，就是逻辑与（&&）逻辑（||）条件（?:）和逗号（，）

所以对于大多数运算符的使用，应该遵守两个准则
* 不确定运算顺序时，使用括号
* 不要在表达式中同事改变并再次使用某个对象

### 算术运算符
优先级相同情况下，二元运算符均满足左结合律

/是整除，只要两边都是整数，根据C++11规定，均向0取整

%是取余数，其符号由左边的数决定

### 逻辑关系运算符
逻辑与和逻辑或均采用**短路求值**的方法，逻辑与仅当左边为真时计算右边，逻辑或仅当左边为假时计算右边

**使用引用可以避免程序对变量的拷贝，对于大型变量来说这样做能提高程序效率**

### 赋值运算符
赋值运算符满足右结合率，这是区别于其他二元运算符的特征

### 递增和递减运算符
除非必须，否则不使用递增递减运算符的后置版本

但为了简洁可以写
```cpp
cout << *iter++;
```

它对iter解引用，输出后将迭代器指针向后移一位

### 条件运算符
条件运算符`?:`将简单的if-else嵌套到单个表达式中，还可以嵌套
```
string finalgrade = (grade>90)?"high pass":(grade < 60) ?"fail":"pass";
```
条件运算符是右结合的，因此嵌套才有意义

### sizeof 运算符
可以求类型所占的字节数，与decltype一样，不会运行得到结果

sizeof数组可以得到数组的大小

### 逗号运算符
逗号运算符有两个运算对象，且和逻辑与、逻辑或以及条件运算符一样，规定了运算的求值顺序：从左到右

逗号运算符先求左侧表达式，然后把表达式结果丢掉，再求右侧表达式，作为求值结果

### 类型转换
不同类型对象进行运算时，会发生类型转换，此时小的类型会提升为大的类型

### 显式转换
强制类型转换的使用方法是

`cast-name<type>(expression)`

其中，cast-name包括

* static_cast
* const_cast
* reinterpret_cast

旧式转化方法为`type(expr)`或`(type)expr`

**慎用类型转换，因为它会干扰正常的类型检查** 

### dowhile
do while 条件语句中出现的变量必须定义在循环之外

### 范围for
范围for等价于
```cpp
for(auto beg=v.begin(),end=v.end();beg!=end;++beg){
  //
}
```
因此，应避免在循环中修改容器的长度，因为循环维持了一个副本end，如果修改了之后，这个副本的信息就失去时效了

### goto
**应避免使用goto语句**
```
goto label; // goto 的语法
label: statement; // 设定label的方法
```
### throw和try
throw可以抛出异常，以`runtime_error`为例
```cpp
if(condition){
  throw runtime_error("blah");
}
```
try-catch可以捕获异常
```cpp
try{
  statements
}catch(runtime_error err){
  cout << err.what() << endl; //获得err中的字符，就是throw中的"blah"
}
```


## 第六章 函数
函数是一个命名了的代码块

执行函数的第一步是（隐式地）定义并初始化它的形参
### 形参和实参
实参是形参的初始值，形参出现在函数定义的地方，实参出现在函数调用的地方

### 函数的返回类型
函数的返回类型不能是数组类型或函数类型，但可以是指向数组或函数的指针

### 局部对象
形参和函数体内部定义的变量统称为**局部变量**

### 局部静态对象
局部静态对象是定义成static的局部对象，它的生命贯穿程序始终，仅仅在第一次经过其定义时会被初始化，比如
```cpp
size_t count_calls(){
  static size_t ctr = 0;
  return ++ctr;
} 
```
这样的函数就可以返回自己被调用的次数，ctr一经初始化后，就一直保留在这个函数中可供下次使用

内置类型的局部静态变量将被初始化为0

### 函数声明
函数与变量一样，只能定义一次，但可以声明多次，函数声明就是函数定义不包括函数体的部分加上分号，函数声明也称为函数原型（function prototype）

### 分离式编译
分离式编译允许我们将程序分割到几个文件中去，每个文件独立编译

比如，编译和链接多个文件，假设函数fact定义在fact.cc中，声明于Chapter6.h中，因此，fact.cc就需要包含Chapter6.h头文件，另外，我们在factMain.cc中创建main函数，main将调用fact函数，则就可以这样编译
```shell
$ CC factMain.cc fact.cc
$ CC factMain.cc fact.cc -o main # 二选一
```

如果我们只修改了其中一个文件，就只需要重新编译修改了的文件，这个过程如下所示
```shell
$ CC -c factMain.cc
$ CC -c fact.cc
$ CC factMain.o fact.o
$ CC factMain.o fact.o -o main # 二选一
```

### 参数传递
形参初始化的机理和变量初始化一样，当形参是引用类型时，就说实参被**引用传递（passed by reference）**，当实参的值拷贝给形参时，我们说是**值传递（passed by value）**

### 使用引用避免拷贝
对于大的类型对象，最好是使用引用传递，如果函数无需改变引用形参的值，最好声明为常量引用

**尽量使用常量引用**，因为使用非常量引用会极大地限制函数所能接受的实参类型，比如，我们无法将const对象、字面值传递给函数

### 数组形参
数组可以通过三种方式传递
* 在数组中做标记示意数组结束
* 使用标准库规范，传递数组的首元素和尾后元素指针
* 显式传递一个表示数组大小的形参

### 传递多维数组
传递多维数组时，数组第二维以及和面所有维度的大小都是数组类型的一部分

### main:处理命令行选项
在命令行中将参数传入到程序
```shell
./a.out a b c d
```
此时对应main函数
```cpp
int main(int argc, char *argv[]){
  ...
}
```
其中`argc`是参数的个数，包括程序本身，一共5个
argv记录了每个参数，真实传入的参数下标从1开始

### 含有可变形参的函数
为了处理相同类型的不同数量的实参，可以使用`initializer_list`类型
```c++
void foo(initializer_list<string> il){
  ...
}
```
它的使用方法几乎与vector相同，唯一的不同就是initializer_list对象中的元素永远是常量，无法改变

### 函数的返回值
函数的返回值的机制和初始化是一样的道理

当函数接受的形参和返回类型都是const对象的引用，则无论是调用还是返回都不会拷贝值

不要返回局部对象的引用或指针，因为对象返回后即被销毁，引用和指针也就没有意义

函数返回的引用值可以当作左值，比如
```cpp
get_val(s,0) = 'A'
```
如果`get_val`返回一个char的引用，则可以这样改变char的值

如果main函数中没有返回，编译器会隐式地插入一条返回0的语句，cpp程序main函数返回0表示执行成功，返回其他值表示执行失败

### 返回数组的指针
虽然不能返回数组，但是可以返回数组的指针，有以下几种方法
```cpp
int (*foo(int a))[10]; // 1

typedef int intArr[10]; // 2
using intArr = int[10]; // 2
intArr *foo(int a);

decltype(someArray) *foo(int a); // 3

auto foo(int a)->int(*)[10]; // 4
```
其中第四个是c++11新加入的尾置返回类型


### 函数重载
如果同一作用域（注意这里）的函数名字相同但形参列表不同，则称为重载（overloaded）函数

拥有顶层const形参无法重载一个没有顶层const的函数
```cpp
Record lookup(Phone);
Record lookup(const Phone);

Record lookup(Phone*);
Record lookup(Phone* const);
```
如果形参是指针或引用，则通过区分其指向的是常量对象还是非常量对象可以实现函数重载
```cpp
Record lookup(Account &);
Record lookup(const Account&);

Record lookup(Account*);
Record lookup(const Account*);
```

**const_cast**和重载
对于这样的一个函数
```cpp
const string &shorterString(const string &s1, const string &s2){
  return s1.size() <= s2.size() ? s1 : s2;
}
```
显然如果函数的参数是非常量的话，我们无法返回一个对常量的引用，此时需要用到const_cast重载函数
```cpp
string &shorterString(string &s1,string &s2){
  auto &r = shorterString(const_cast<const string&>(s1),const_cast<const string&>(s2));
  return const_cast<string&>(r);
}
```

### 重载与作用域
注意重载的定义，是相同作用域下，如果有更小的作用域中存在同名函数，将覆盖外部作用域中的函数

### 默认实参
为某个形参提供一个默认实参，它后面的形参都必须要有默认值

### 内联函数和constexpr函数
调用函数一般比求等价的表达式要慢一点，因为它包括一系列工作：调用前要先保存寄存器，并在返回时恢复、可能需要拷贝实参、程序转向一个新的位置继续执行。

**内联函数可以避免函数调用的开销**

**内联只是向编译器发出的一个请求，编译器可以选择忽略这个请求**


### 调试帮助
**assert**是一种预处理宏，它位于cassert文件中，所谓预处理宏其是一个预处理变量，可以作用在一个表达式上
```cpp
assert(expr)
```
当表达式为假时，assert输出信息并终端程序的运行

**NDEBUG**预处理变量控制着assert的行为，当它被定义时，程序人跳过所有的assert语句

我们也可以自己编写条件调试代码
```
#ifndef NDEBUT
cerr << __func__ << "something is " << something;
#endif
```
c++定义了一些帮助调试的名字
* __func__,当前调试函数的名字
* __FILE__,文件名
* __TIME__,编译时间
* __DATE__,编译日期

### 实参类型转换
为了确定重载函数的最佳匹配，编译器将实参类型到形参类型的转换划分成几个等级，具体排序如下
* 精准匹配
  * 实参类型和形参类型相同
  * 实参从数组类型或函数类型转换成对应的指针类型
  * 向实参添加顶层const或者从实参中删除顶层const
* 通过const转换实现的匹配
* 通过类型提升实现的匹配
* 通过而算数类型转换或指针转换实现的匹配
* 通过类类型转换实现的匹配

调用重载函数时应尽量避免强制类型转换，如果在实际应用中确实需要强制类型转换，则说明我们设计的形参集合不合理

### 函数指针
以下是一个函数指针
```cpp
bool (*pf)(const string &,const astring &);
```
它指向一个以两个const string引用为参数，返回一个bool值的函数，注意括号的必要，否则它就是一个返回bool指针的函数

当我们把函数名作为一个值使用时，该函数自动地转换成指针
```cpp
pf = lengthCompare;
pf = &lengthCompare; // 等价语句
```
且我们使用函数指针调用函数时，无须提前解引用指针
```cpp
bool b1 = pf("hello","goodby");
```

### 函数指针形参
虽然不能定义函数类型的形参，但形参可以是指向函数的指针，此时类似使用数组指针一样，我们可能需要用到`decltype`或者`typedef`或者`using`或者尾置返回类型方式来简化语句

## 第七章 类
类的基本思想是数据抽象（data abstraction）和封装（encapsulation），数据抽象是一种依赖于接口（interface）和实现（implementation）分离的编程技术。类的接口包括用户所能只能的操作；类的实现包括类的数据成员、负责接口实现的函数体以及定义类所需的各种私有函数。

作为一个设计良好的类，既要有直观且易于使用的接口，也必须具备高效的实现过程

成员函数的声明必须要类的内部，定义既可以在类的内部也可以在外部，非成员函数的声明和定义均在类的外部

this是指向当前对象的指针，因为总是指向当前对象，它是一个常量指针


### const 成员函数
声明了const成员函数后，就不可以通过this来修改成员变量
```cpp
int dog() const{};//声明方法，在形参列表后加上const
```
这样的函数称为常量成员函数

### 在类外定义成员函数 
使用作用域运算符在类外定义成员函数
```cpp
double className::func(){
  return 1.0;
}
```

### 非成员函数
add、read、print等函数属于类的接口组成成分，但不属于类本身，所以我们把它们定义为非成员函数

通常我们定义read、print函数接受istream引用（IO类不可拷贝，即不可值传递）作为参数，并返回，这样可以控制输入流，并能够得到输入是否成功的标志，而且可以继续输入输出
```cpp
istream &read(istream &is,...){
  is >> ...
  return is;
}
```
```cpp
ostream &print(ostream &os,...){
  os << ...
  return os;
}
```
这样我们就可以
```cpp
print(something) << endl;
```

### 构造函数
构造函数的任务是初始化对象的数据成员

类通过默认构造函数（default constructor）来控制默认初始化过程，默认构造函数无任何实参，如果我们没有显示定义构造函数，编译器就会为我们隐式地定义一个默认构造函数

如果我们定义了其他构造函数，除非我们再构造一个默认构造函数，否则类将没有默认的构造函数，C++11中，我们可以简单地定义一个默认构造函数
```cpp
classname() = default;
```
### 构造函数初始值列表初始化
可以使用构造函数初始值列表初始化类中的成员
```cpp
className(int n,const string& s):N(n),name(s){}
```

### 拷贝、赋值和析构
没有显式定义的情况下，编译器会为我们默认合成默认的拷贝、赋值和析构操作，但有时，这些合成的操作无法正常工作，比如当我们需要分配和管理动态内存时

### 访问控制和封装
我们通过访问说明符加强类的封装性，定义在private说明符之后的成员可以被类的成员函数访问，但是不能被使用该类的代码访问，定义在public之后的成员符在整个程序内可被访问

**class和struct的唯一区别就是默认访问权限不同，class是private，struct是public**

### 友元
类可以允许其他类或者函数访问它的非公有成员，方法是将其他类或者函数声明成为它的友元（friend）,只要在类内声明一个以friend关键字开头的函数声明语句即可
```cpp
friend int a();
```
一般来说，最好在类的定义开始或结束前的位置集中声明友元

封装的两个优点
* 确保用户代码不会无意间破坏封装对象的状态
* 被封装的类的具体实现细节可以随时改变，而无需调整用户级别的代码

### 类的其他特性
定义在类内的成员函数是自动inline的

我们可以声明某个变量为mutable,这样即便在const成员函数中，它也是可改变的
```cpp
class Screen{
  public:
  mutable size_t ctr;
}
```

我们可以让成员函数返回*this，来在函数返回的同时获得原来的对象，通常我们还会将函数的返回类型设置为引用类型，这样不仅能节省拷贝的时间，得到原对象，且还可以当作左值使用
```cpp
myScreen.display(cout).set('#');
```

需要注意的是，一个const成员对象如果以引用形式返回*this，则会返回一个常量引用，即我们无法通过这个指针来更改这个对象

成员函数相互调用时，this指针在其中隐式传递，因此，我们可以重载display函数，来解决display返回const对象而无法set的问题

```cpp
class Screen{
  public:
  Screen &display(std::ostream &os){
    do_display(os); return *this;
  }
  const Screen &display(std::ostream &os) cons{
    do_display(os); return *this;
  }
  private:
  void do_display(std::ostream &os) const {os << contents;}
}
```
display是重载函数，它根据接受的对象是否是const来判断应该调用哪一个

### 类声明
可以把类的声明和定义分开
```cpp
class Screen;
```
这种被称为前向声明（forward declaration），它在声明后定义前都是一个不完全类型（incomplete type），仅能在有限的情景下使用：定义指向这种类型的指针或引用，也可以声明（但不能定义）以不完全类型作为参数或者返回类型的函数

### 友元类
可以把别的类定义为自己的友元类
```cpp
friend class SomeClass;
```
则友元类的成员函数可以访问本类中的所有非公有成员

注意友元关系不存在传递性，每个类负责控制自己的友元类或友元函数

### 类的作用域
一个类就是一个作用域，因此在外部定义时需要提供类名和函数名，此外，因为在类外定义的时候，返回类型在类名之前，因此，返回类型不能为类内定义的某个类型，除非在外部也声明或者在返回类型前加上类作用域

编译器处理完类中的全部声明后才会处理成员函数的定义

作用域问题会导致很多问题，比如类外的成员函数不能直接返回类内定义的某类型、相互依赖的类的声明和定义的前后顺序关系等等

### 构造函数初始值列表
构造函数初始值列表和赋值是不同的，我们似乎也可以在构造函数体内对变量进行赋值，但是这回引发一些错误，这正是由初始化与赋值的不同而导致的，比如常量对象和引用，它们就必须要进行初始化，常量对象也不可赋值

类内成员初始化的顺序是它们在类中定义的顺序（虽然我做了实验，似乎不是这样），因此在构造函数的初始值列表中，我们可能想用某个成员初始化另一个成员，此时就要考虑它们的初始化顺序

构造函数也可以提供默认实参，当每个参数都有默认实参时，它就成为了一个默认构造函数

### 委托构造函数
C++11中扩展了构造函数的功能，使得我们可以定义委托构造函数
```cpp
className(int a,int b,int c):A(a),B(b),C(c){}
className():className(0,0,0){}//委托构造函数
```

使用默认构造函数的方法不是这样
```cpp
className a();
```
实际上这样做实在定义一个函数，正确使用的方法是
```cpp
className a;
```
错误的使用方法尤其是当我们向调用所有参数都有默认值的默认构造函数时写出来的东西

### 转换构造函数
当构造函数仅有一个实参时，它实际上定义了转换为此类型的隐式转换机制，这种构造函数称为**转换构造函数**

比如`item`是一个`Sales_data`的对象，而`Sales_data`有一个仅仅接受一个`string`对象的构造函数，`combine`是`Sales_data`的成员函数，接受一个`Sales_data`类型的参数，那么下面的调用将引发隐式类型转换
```
string a = "123";
item.combine(a);
```
这样的调用是合法的，`a`将隐式被转换为`Sales_data`


但是我们仅仅允许一步类型转换，比如我们不可以这样写
```cpp
item.combine("123");
```
因为这要先将"123"转换为string，然后再转换为Sales_data

这种转换允许在一些可能需要的地方
```cpp
string b = "123";
Sales_data a = b;
```

我们可以通过将构造函数声明为explicit的方法来禁止隐式转换

比如接受一个单参数const char*的string函数就不是explicit的，而接受一个容量参数的vector构造函数，就是explicit的，这使得
```cpp
string a = "123"; // 合法的
vector<int> v = 1; // 不合法，如果不是explicit，则会有得到一个包含1个元素的vector
```

### 聚合类
当一个类所有成员都是public的，没有定义任何构造函数，没有类内初始值，没有基类和virtual函数，它就是一个聚合类，聚合类可以通过花括号直接初始化
```cpp
struct Data{
  int ival;
  string s;
};

Data val1 = {0,"Anna"};
```
只要花括号中变量出现的顺序和之前声明的一致

### 字面值常量类（？？？）
看书吧，这节根本看不懂，也不知字面值常量类有啥用

### 类的静态成员
类的静态成员直接与类相关，不与任何对象绑在一起，不包括this指针，声明静态成员，只要在前面加上一个static就可以了

可以使用作用域运算符直接访问静态成员
```cpp
double r;
r = Account::rate();
```
也可以用对象访问，就和访问成员一样

成员函数可以不通过作用域访问静态成员

静态成员声明时不能初始化（除非是静态常量成员），必须在类的外部对每个静态成员初始化，一般最好的方法是将静态数据成员的定义与其他非内联函数的定义放在同一个文件中

静态成员可以是不完全类型


## 第八章 IO库

本节的习题主要问题是
* 没有对文件对象的打开是否成功作出判断
* cin.clear()后没有cin.ignore(100,'\n')

### IO类
IO的头文件
* iostream:istream,ostream,iostream
* fstream:ifstream,ofstream,fstream
* sstream:istringstream,ostringstream,stringstream

ifstream和istringstream都继承自istream

ofstream和ostringstream都继承自ostream

IO对象无拷贝或赋值，且读写一个我IO对象会改变其状态，因此不能是const的

### 条件状态
流对象可以当作条件，来确认其是否处于良好状态，是否有效

流对象有三个错误位，分别是badbit eofbit和failbit，遇到系统级错误时，badbit被置位，达到文件结束时，eofbit和failbit被置位，如果这三个任意一个被置位，则检测流状态都会失败

执行`clear`可以复位所有标志位

### 输出缓冲
每个输出流都管理一个缓冲区，缓冲刷新才会真正将输出输出到屏幕上，导致缓冲刷新的原因有
* 程序正常结束
* 缓冲区满时
* 操纵符如endl
* 关联流

刷新缓冲区
```cpp
cout << "hi" << endl; //加一个换行符，刷新
cout << "hi" << fluish; // 刷新
cout << "hi" << ends; // 加一个空格，刷新
```

如果想每次输出直接刷新，可以使用unitbuf操纵符
```cpp
cout<<unitbuf; //所有输出立即刷新
cout<< nounitbuf; //返回正常缓冲方式
```

**程序崩溃时，缓冲区不会被刷新**

### 关联输入和输出流：见书上吧

### 文件输入和输出
头文件fstream定义了三个类型支持文件输入输出，ifstream读文件，ofstream写文件，fstream读写文件
```cpp
ifstream in(ifile); //构造一个ifstream并打开指定文件
```
或者可以声明后调用`open`来打开文件，对应的用`close`关闭文件，只有关闭文件后，才能再打开另一个文件，当一个fstream对象被销毁时，close会自动被调用


### 文件模式
话不多说
```cpp
ofstream out("file1",ofstream::out);
ofstream out("file1",ofstream::out | ofstream::trunc);
ofstream out("file1",ofstream::out | ofstream::app;
```

### string流
istringstream从string中读数据，ostringstream向string中写数据

## 第九章 顺序容器
顺序容器类型
* vector
* deque,双端队列
* list，双向链表
* forward_list，单项链表
* array，固定大小数组
* string

头文件名和类型名一样

**通常，vector是最好的选择，除非有很好的理由选择别的容器**

### 迭代器
迭代器的范围由一对迭代器表示，组成左闭合区间

### 容器类型成员
容器类型可以在不了解容器中元素类型的情况下使用比如
```cpp
list<string>::iterator iter;
iter::value_type a; // string
```

### begin和end成员
可以用`rbegin`来得到反向迭代器，此时++的作用就等于--

容器的迭代器可以是const的，只要用`.cbegin()`即可，如果容器本身是const的，那么即便使用`.begin()`返回的类型也是`const_iterator`

**当不需要写访问时，应使用cbegin和cend** 

### 容器定义和初始化
容器定义的方法有
* C c; 默认构造函数，初始化空容器，array则会自动调用元素的默认初始化方法
* C c1(c2); 拷贝初始化，容器类型和元素类型必须相同
* C c{a,b,c...}; C c={a,b,c...}; 初始化为初始化列表中元素的**拷贝**
* C c(b,e); 初始化为迭代器b和e范围中的元素，元素必须**相容**
* C seq(n); seq包括n个元素，且次构造函数是explicit的
* C seq(n,t); seq包括n个初始化为t的元素

元素类型不同但相容的容器（容器类型可以不同）之间的元素拷贝可以通过迭代器完成

### 标准库array
标准库array有固定大小
```cpp
array<int,42>
```
与内置数组不同，标准库array可以赋值

### 容器赋值运算
这里先区分初始化和赋值的区别，初始化在变量定义时发生，赋值在变量定义后发生

容器的赋值运算有
* c1 = c2
* c = {a,b,c...} ，array不适用
* swap(c1,c2),c1.swap(c2)交换c1和c2中的元素，swap通常比从c2向c1拷贝元素快的多，因为swap只是交换了两个容器的内部数据结构，并未交换容器本身，除了array外
* seq.assign(b,e) 将seq替换为迭代器b和e之间的元素，迭代器不可指向seq
* seq.assign(il) 将seq中的元素替换为初始化列表il中的元素
* seq.assign(n,t) 将seq中的元素替换为n个值为t的元素

几点值得注意的地方
* assign方法无法作用在array上
* assign方法支持相容的类型赋值
* swap不移动元素意味着除了string以外，指向容器的迭代器、引用和指针在swap操作后不会失效，它们指向原来指向的元素，只是这些元素已经属于不同的容器了，但swap array对象会真正交换它们的元素，因此swap array后，指针、引用、迭代器等指向的元素值会发生改变

### 容器大小操作
empty、size、max_size

### 关系运算符
保存相同元素的相同容器可以通过关系运算符进行比较，比较方式与string类似

### 顺序容器操作
除array外所有容器都提供灵活的内存管理，在运行时可以动态添加或删除元素来改变容器大小，下面列出顺序容器（非array)添加元素的操作，这里方法不一定适用于forward_list，forward_list之后单独会列出
* c.push_back(t) 在容器尾部添加元素
* c.emplace_back(args) 在容器尾部添加由args创建的元素
* c.push/emplace_front vector string 不支持
* c.insert(p,t) 在迭代器p指向的元素之前添加元素
* c.emplace(p,args) ...
* c.insert(p,n,t) 在迭代器p指向的元素之前插入n个值为t的元素，返回指向新添加的第一个元素的迭代器
* c.insert(p,b,e) 将迭代器b和e之间的元素插入到p指向的元素之前，b和e不能指向c中的元素，返回指向新添加的第一个元素的迭代器
* c.insert(p,il) il是一个花括号包围的元素值列表

**向一个vector、string或deque**插入元素会使所有指向容器的迭代器、引用和指针失效

**在一个vector或string尾部之外的任何位置或deque的首位之外的任何位置添加元素，都需要移动元素**

使用insert的返回值，可以在容器的一个特定位置反复插入元素
```cpp
list<string> lst;
auto iter = lst.begin();
while(cin>>word)
  iter = lst.insert(iter,word); // 等价于调用push_front
```

### 访问元素
每个顺序容器都有一个front成员函数，除了forward_list之外的所有顺序容器都有一个back成员函数，这两个操作分别返回首元素和尾元素的引用
* c.back()，返回尾元素的引用
* c.fromt(),返回首元素的引用
* c[n]，返回下标为n的元素的引用，若n>=c.size(),则函数的行为未定义
* c.at(n)，返回下标为n的元素的引用，如果下标越界，则抛出一个out_of_range异常

如果我们想通过改变上面得到的变量来改变元素的值，则需将变量定义为引用类型

### 删除元素
* c.pop_back(),删除尾元素，返回void
* c.pop_front()，删除首元素，返回void
* c.erase(p)，删除迭代器p指向的元素，返回一个指向被删元素之后元素的迭代器
* c.erase(b,e)，删除迭代器b和e所指定范围内的元素，返回一个指向最后一个被删元素之后元素的迭代器
* c.clear()，删除c中的所有元素，返回void

### 特殊的forward list操作
forward list作为一个单向链表，无法删除当前指向的元素，因为这会改变前一个元素的后继，因此它的添加和删除元素的方法是对指针后一个元素进行操作的，为此引入了首前迭代器，具体方法见书上


### 改变容器大小
* c.resize(n)
* c.resize(n,t),调整大小为n，任何新的元素为t

### 容器操作可能使迭代器失效
如题，添加或删除元素时可能造成迭代器失效，因此必须正确地重新定位迭代器

**不要保存end返回的迭代器**,end迭代器容易失效，且，C++标准库中end()操作很快，因此需要时直接调用即可

### vector的增长
向vector中添加元素时,如果没有空间容纳元素,因为元素必须连续储存,容器必须分配新的内存空间来保存已有元素和新元素,将已有元素从旧位置移动到新空间中,然后添加新元素,为了避免反复拷贝的代价,vector和string通常会分配比新的空间需求更大的内存空间,容器预留这些空间作为备用.可以通过.capacity()访问当前容器容量。0