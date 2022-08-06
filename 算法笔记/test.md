网络隔绝
物理结构
外网  ------ 内网
（编码）  ---视频(外-》 内 HDMI)/云台控制(内--> 外 232)/报警(外-》 内 485）-  （解码器）
编码
（编码器（1-1）：
1. 视频对应关系
2. 云台指令接受
3. 报警指令的发送

（解码器（1-1）：
1. 视频对应关系
2. 云台指令发送
3. 报警指令的接受



云台指令发送
报警指令的接受

      编码器
 视频（IPC）  --》 （H264）
 云台指令(解码器)  -网络-> 球季
 报警指令（IPC） -串口-> 解码器

       解码器
 显示器（）  《-- （H264）
 (编码器)  <-串口- 云台指令
 报警指令（IPC） -串口-> 解码器

 视频
 对应关系
map  解码器(key)  编码器(value)
     1-1           1-2

云台指令
解码器1-2
1. 串口指令发送和接受
2. 新增一个BH协议

CPtz::Start()
{
    switch(pro){
        case DH:
        {}
        ..
    }
}

class DH{};
class DHExampe1:{};
class DHExampe2{};
//工厂模式
ptzPtr = getComponentInstance("DH", channel);
ptzPtr->start();

map
key(string "DH") value(this指针)
ptzPtr->start();
报警指令
1-2