## 汇编指令相关操作

### 问题1. 如何单步执行汇编指令

进入gdb后，首先输入：
```c++
set disassemble-next-line on
```
然后可以通过指令si相当于step into(单步进入)，ni相当于step over(单步跳过)。

### 问题2. 如何断点指定的汇编行

