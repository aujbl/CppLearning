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

11. 





