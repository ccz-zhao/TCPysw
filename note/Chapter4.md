# 基于TCP的服务器端/客户端

## 4.1 理解TCP和UDP

TCP(transmission control protocol)传输控制协议，面向连接，基于流(stream)的套接字。

### TCP/IP协议栈

![](Chapter4_img/Screenshot%20from%202022-03-10%2014-27-35.png)

### 链路层

### IP层

处理向目标传输的路径

IP本身是面向消息的，不可靠的协议。
传输中发生路径错误，可以选择其他路径；但是无法处理数据丢失或者错误的问题。

只关注一个数据包的传输过程，多个数据包的传输顺序及传输本身是不可靠的。

### TCP/UDP层

TCP和UDP层以IP层提供的路径信息为基础完成实际的数据传输。
TCP可以保证可靠的数据传输。

作用：数据交换过程中确认对方已收到数据，并重传丢失的数据，在不可靠的IP层完成可靠的通信。

![](Chapter4_img/Screenshot%20from%202022-03-10%2014-40-52.png)

### 应用层

套接字

## 4.2 实现基于TCP的服务器端/客户端

### TCP服务器端的默认函数调用顺序

![](Chapter4_img/Screenshot%20from%202022-03-10%2014-44-30.png)

#### socket()

#### bind()

#### listen() 进入等待连接请求状态

### TCP客户端的默认函数调用顺序

客户端的内容：创建套接字，请求连接

![](Chapter4_img/Screenshot%20from%202022-03-20%2016-33-50.png)

#### connect()

### 基于 TCP 的服务器端/客户端函数调用关系

![](Chapter4_img/Screenshot%20from%202022-03-20%2016-40-28.png)

