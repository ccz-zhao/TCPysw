# listen 函数

进入等待连接请求状态

## 定义

```c
#include <sys/socket.h>

int listen(int sock, int backlog);
```

成功返回0，失败返回-1。

### sock

希望进入等待连接请求状态的套接字文件描述符，传递的描述符套接字参数成为服务器端套接字(监听套接字)。

### backlog

连接请求等待队列的长度