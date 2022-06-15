# socket函数

## 定义

```c
#include <sys/socket.h>

int socket(int domain, int type, int protocol);

```

成功返回fd，失败返回-1。

### domain:协议族(protocol family)

|   名称  | 协议族  |
|:------:|:------:|
|PF_INET |IPv4    |
|PF_INET6|IPv6    |
|PF_LOCAL|本地通信UNIX协议族|
|PF_PACKET|底层套接字|
|PF_IPX  |IPX Novell|

### type:套接字类型

#### 1: SOCK_STREAM 面向连接的套接字

可靠的，按序传递的，基于字节的面向连接的数据传输方式的套接字。

#### 2: SOCK_DGRAM 面向消息

不可靠的，不按序传递的，以数据的高速传输为目的的套接字。

### protocol:最终采取协议

一般情况下传递前两个参数即可创建所需套接字。所以大部分情况下可以向第三个参数传递0。
