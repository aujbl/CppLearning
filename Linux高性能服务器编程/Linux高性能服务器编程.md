# 1 TCP/IP协议族

1. 数据链路层：ARP协议（IP -> MAC）

2. 网络层
    
    1. IP协议：确定两台主机之间的通信路径，寻找合适的下一跳

    2. ICMP协议（因特网控制报文协议）：检测网络连接

3. 传输层：为两台主机上的应用程序提供端到端的通信

    1. TCP协议：基于流

    2. UDP协议：基于数据报

    3. SCTP协议（流控制传输协议）

4. 应用层：负责处理应用程序的逻辑（ping/telnet/OSPF/DNS等）

5. 封装：TCP报文段/UDP数据报 -> IP数据报 -> 以太网帧

6. 分用

7. ARP协议工作原理：主机向所在网络广播ARP请求，请求包括目标机器的网络地址。网络上的所有机器都收到请求，但只有目标机器回应一个ARP应答，其中包含自己的物理地址






# 第5章 Linux网络编程基础API

1. ```sys/socket.h```socket基础API；```netdb.h```网络信息API：主机名和IP地址转换、服务名称和端口号转换

2. 主机字节序（小端）、网络字节序（大端：整数高位在低地址）

    ```cpp
    #include <netinet/in.h>
    unsigned long int htonl(unsigned long int hostlong);                // host to network long
                                                                        // 长整型主机字节序数据转换为网络字节序数据
    unsigned long short htons(unsigned long int hostshort);                // host to network short
    unsigned long int ntohl(unsigned long int hostlong);                // network to host long
    unsigned long short ntohs(unsigned long int hostshort);                // network to host long
    ```
    
3. 专用socket地址

    ```cpp
    // 通用socket地址
    struct sockaddr{
        sa_family_t sa_family;
        char sa_data[14];
    }；
    // 专用socket地址
    sockaddr_in
    {
        sa_family_t sin_family;             // 地址族
        u_int16_t sin_port;                 // 端口号
        struct in_addr sin_addr;            // IPv4
    };
    struct in_addr{
        u_int32_t s_addr;                   // 网络序IPv4地址
    }；
    // 所有专用socket地址在实际使用时都要转化为通用socket地址
    ```

4. IP地址转换函数

    ```cpp
    #include <arpa/inet.h>
    in_addr_t inet_addr(const char* strptr);
    int inet_aton(const char* cp, struct in_addr* inp);
    char* inet_ntoa(struct in_addr in);                     // 将网络序整数地址转换为点分十进制IPv4地址

    int inet_pton(int af, const char* src, void* dst);
    const char* inet_ntop(int af, const void* src, char* dst, socklen_t cnt);
    ```

5. 在Linux中，socket是一个可读/可写/可控制/可关闭的文件描述符

6. socket命名：将一个socket和socket地址绑定

    ```cpp
    #include<sys/types.h>
    #include <sys/socket.h>
    int bind(int sockfd, const struct sockaddr * my_addr, socklen_t addrlen);
    // 服务端socket常需要命名，客户端socket通常采用匿名
    ```

7. 监听socket

    ```cpp
    #include <sys/socket.h>
    int listen (int sockfd, int backlog);
    ```

8. accept只是从监听队列中取出连接，而不论连接处于何种状态

9. 客户端发起连接

    ```cpp
    int connect(int sockfd, const struct sockaddr *serv_addr, socklen_t addrlen);
    ```

10. 关闭连接

    1. close()关闭连接时将引用计数-1，只有当fd的引用计数为0时，才真正关闭连接

    2. ```int shutdown(int sockfd, int howto);```可以分别关闭读写，或同时关闭

11. TCP数据读写

    ```cpp
    #include <sys/types.h>
    #include <sys/socket.h>
    ssize_t recv(int sockfd, void *buf, size_t len, int flags);
    ssize_t send(int sockfd, const void* buf, size_t len, int flags);
    ```

    1. recv读取sockfd上的数据，buf和len指定读缓冲区的位置和大小

    2. send往sockfd上写数据，buf和len指定写缓冲区的位置和大小

    3. flags参数只对send和recv的当前调用生效

12. UDP数据读写

    ```cpp
    ```cpp
    #include <sys/types.h>
    #include <sys/socket.h>
    ssize_t recvfrom(...);
    ssize_t sendto(...);
    ```

    1. UDP通信没有连接，每次读取数据都要获取发送端的socket地址

    2. recvfrom/sendto也可以用于面向连接的socket的数据读写

13. 通用数据读写

    ```cpp
    ssize_t recvmsg(...);
    ssize_t sendmsg(...);
    ```

14. 带外数据到达的两种常见方式：I/O复用产生的异常事件和SIGURG信号，用```int sockatmark(int sockfd);```判断sockfd是否处于带外标记

15. 地址信息函数

    ```cpp
    int getsockname(...);
    int getpeername(...);
    ```

16. 读取和设置socket文件描述符属性的方法

    ```cpp
    int getsockopt(...);
    int setsockopt(...);
    ```

17. SO_REUSEADDR强制使用被处于TIME_WAIT状态的连接占用的socket地址

18. SO_RCVBUF和SO_SNDBUF缓冲区大小，不小于某个最小值，最小值用来确保TCP连接拥有足够的空闲缓冲区来处理拥塞

19. SO_RCVLOWAT和SO_SNDLOWAT：用来判断socket是否可读可写

20. SO_LINGER：用于控制close系统调用在关闭TCP连接时的行为

21. 网络信息API

    ```cpp
    gethostbyname();                // 根据主机名称获取主机的完整信息
    gethostbyaddr();                // 根据IP获取主机的完整信息
    getservbyname();                // 根据名称获取某个服务的完整信息
    getservbyport();                // 根据端口号获取某个服务的完整信息
                                    // 四个函数都是不可重入的，非线程安全的（可重入版本函数名尾部_r）

    getaddrinfo();                  // 既能通过主机名获得IP地址，也能通过服务名获得端口号
    getnameinfo();                  // 通过socket地址同时获得以字符串表示的主机名和服务名
    ```

    1. 可以用服务名称来代替端口号

# 第6章 高级I/O函数

1. pipe函数：创建由两个文件描述符构成的管道```int pipe(int fd[2]);      // fd[0]读取，fd[1]写入```

2. dup函数：创建一个新的文件描述符，指向和原文件描述符相同的文件、管道或网络连接

3. readv()将数据从文件描述符读到分散的内存块中（分散读）；writev()将多块分散的内存数据一并写入文件描述符中（集中写）

4. sendfile():在两个文件描述符之间直接传递数据（内核中操作），避免了缓冲区之间的数据拷贝，效率高（零拷贝）

    ```cpp
    #include <sys/sendfile.h>
    ssize_t sendfile(int out_fd, int in_fd, off_t* offset, size_t count);       // in_fd必须指向真实文件
    ```

5. mmap()用于申请一段内存空间，作为进程间通信的共享内存；munmap()释放由mmap创建的内存空间

6. splice()用于在两个文件描述符之间移动数据，零拷贝操作

7. tee()在两个管道文件描述符之间复制数据，零拷贝操作。它不消耗数据，源数据仍可用于后续操作

8. fcntl()提供了对文件描述符的各种控制操作，在网络编程中，常用来将一个文件描述符设置为非阻塞的






# 第七章 Linux服务器编程规范

1. rsyslogd守护进程，既能接收用户进程输出的日志，也能接收内核日志

2. syslog函数：应用程序使用该程序与rsyslogd守护进程通信

3. UID/EUID/GID/EGID

4. 进程组：```getpgid();    setpgid();    ```

5. 一些有关联的进程组将形成一个会话```setsid();```

6. 系统资源限制

    ```cpp
    int getrlimit(int resource, struct rlimit *rlim);               
    int setrlimit(int resoutce, const struct rlimit *rlim);
    ```

7. 改变工作目录和根目录

    ```cpp
    #include <unistd.h>
    char* getcwd(char* buf, size_t size);           // 获取当前工作目录
    int chdir(const char* path);                    // 改变进程工作目录
    int chroot(const char* path);                   // 改变进程根目录
    ```

# 第八章 高性能服务器程序框架

1. 服务器模型：C/S模型，P2P模型

2. 服务器基本模块

    1. I/O处理单元：等待并接受新的客户连接、接收客户数据、将响应数据返回给客户端

    2. 逻辑单元（一个进程或线程）：分析处理客户数据，返回结果

    3. 网络存储单元

    4. 请求队列

3. 




# Vim

1. 命令模式

    1. aiosAIOS

    2. h：左，j：下，k：上，l：右

    3. 自动格式化代码```gg=G```

    4. %对应括号

    5. x：删除但个字符，不改变工作模式

    6. dw：删除单词

    7. shift+d：删除光标至行尾

    8. 0：回到行首

    9. $：行尾

    10. g，G

    11. r：替换单个字符

    12. v：切换为可视模式，选择多个字符

    13. dd：删除指定行

    14. Ndd：删除N行

    15. p：粘贴到下一行，P：粘贴到上一行

    16. yy：复制一行

    17. Nyy：复制多行

    18. /word：文本中查找word

    19. *：文本中选中单词，然后往后搜索该单词

    20. #: 文本中选中单词，然后往前搜索该单词

    21. :s /word/new_word 单行内替换

    22. :%s/word/new_word/g 通篇替换

    23. u:撤销

    24. ctrl+r:撤销撤销

    25. :sp：上下分屏，ctrl+w切换

    26. :vsp：垂直分屏，ctrl+w切换

    27. K：将光标至于待查看单词，跳转至man手册

    28. [+d：查看宏定义

    29. !：执行shell命令


# GCC

1. 预处理->编译->汇编->链接

    1. 预处理 -E：展开宏，头文件；替换条件编译；删除注释/空行/空白

    2. 编译 -S：检查语法规范

    3. 汇编 -c：将汇编指令翻译成机器指令

    4. 链接：数据段合并，地址回填

2. -I：指定头文件位置

3. -g：编译时添加调试信息

4. -Wall：warning all

5. -D：编译时向程序动态注册宏

6. 静态库制作

    1. 将.c文件生成.o文件

    2. 使用ar制作静态库.a

    3. 编译时添加静态库```gcc test.c lib.a -o a.out```
    4. 制作头文件

7. 动态库制作

    1. 将.c文件生成.o文件

    2. 使用gcc -shared 制作动态库 ```gcc -shared lib.so a.o b.o```

    3. 编译可执行程序时，指定所使用的动态库 -l指定库名，-L指定库路径

    4. 链接器和动态链接器不一样（-l，-L是给链接器指定路径）

    5. 需要给动态链接器指定动态库路径
        
        1. 修改环境变量

        2. 修改终端配置文件```.bashrc```

        3. 拷贝动态库到lib目录

        4. 配置文件```ld.so.conf```

# GDB

1. finish

2. 条件断点```b 41 if i = 5```

3. ptype

4. backtrace:查看栈帧，frame切换栈帧

5. display/undisplay：一直跟踪



# makefile：1个规则/2个函数/3个自动变量

1. 1个规则

    1. 目标：依赖文件
        命令

    ```
    hello:hello.c
        gcc hello.c -o hello


    hello:hello.o
        gcc hello.o -o hello
    hello.o:hello.c
        gcc -c hello.c -o hello.o
    ```
    make执行

        1. 检查依赖是否不存在，不存在时检查是否存在生成依赖的条件

        2. 检查目标是否是最新，否则更新目标

        3. ALL指定终极目标，否则第一行是中级目标

2. 2个函数

    1. ```src = $(wildcard ./*.c)```:匹配当前工作目录下的所有.c文件，组成列表赋给src

    2. ```obj = $(patsubst %.c, %.o, $(src)):将参数3中，包含参数1的部分，替换为参数2

    3. 清理文件
        ```
        clean:                              # clean无依赖
            -rm -rf $(obj) a.out            # '-'rm，遇到错误不报错
        ```

3. 3个自动变量

    1. $@：在规则的命令中，表示规则中的目标

    2. $<：在规则的命令中，表示第一个依赖条件

    3. $^：在规则的命令中，表示所有的依赖条件；改变量可以将依赖依次取出，应用模式规则

4. 模式规则

    1.  ```
        %.o:%.c
            gcc -c $< $@
        ```
        
    2. 静态模式规则```$(obj):%.o:%.c```

    3. 伪目标：```.PHONY: clean ALL```

# 系统调用

1. open

    1. 创建文件时，可以指定文件权限。文件权限同时受umask影响 文件权限 = mode & ~umask

    2. 可以通过```strerror()```打印错误信息

    