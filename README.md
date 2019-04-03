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