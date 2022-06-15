# accept 函数

受理客户端连接请求。在调用listen函数后，按序受理。受理请求意味着进入可接受数据的状态。accept函数自动创建套接字，并连接到发起请求的客户端。

## 定义

```c
#include <sys/socket.h>

int accept(int sock, struct sockaddr * addr, socklen_t * addrlen);
```

成功返回创建的fd，失败-1

### sock

服务器套接字的文件描述符

### addr

保存发起连接请求的客户端地址信息的变量地址值

### addrlen

addr结构体的长度