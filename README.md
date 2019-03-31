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