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