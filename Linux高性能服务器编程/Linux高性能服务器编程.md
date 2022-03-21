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
    sockaddr_in

