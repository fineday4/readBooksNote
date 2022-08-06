## const_cast说明

### 作用：将const类型转为非const，以达到修改其内容的目的。

### 实验：

```c++
#include <iostream>

using namespace std;

void printTest(const char* buf)
{
    cout << buf << endl;
    char* tmpBuf = const_cast<char*>(buf);
    tmpBuf[0] = 'T'; 
    cout << buf << endl;
}

int main(int argc, char* argv[])
{
    if(1  == argc) {
        const char buf[] = "XHH test"; //case 1
        printTest(buf);
    } else {
        const char *buf = "XHH test"; //case 2
        printTest(buf);
    }
    return 0;
}
```
### 结论：
1. <font color=red face="楷体">使用const_cast可以将const修改为非const进而实现修改const变量的内容；</font>
2. <font color=red face="楷体">这不是一个好的关键字，因为这改变了函数的意图，即函数入参使用const修饰的目的就是为了不修改该变量，而const_cast恰恰违背了这个意图；</font>
3. <font color=red face="楷体">const_cast修改为非const后依然不可以修改不可写的区，如上述case 2中buf在.data区，该区为只读区，索引在printTest中就算使用const_cast修改为非const后依然无法修改其内容，强制修改就会导致其报错。这更进一步说明了const_cast不是一个好的关键字。</font>


