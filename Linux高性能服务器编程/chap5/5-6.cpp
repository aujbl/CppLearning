#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>


int main(int argc, char* argv[]){

    const char* ip = argv[1];
    int port = atoi(argv[2]);

    int sock = socket(PF_INET, SOCK_STREAM, 0);
    assert(sock >= 0);

    struct sockaddr_in address;     // 专有socket地址
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);             // hton:主机序转成网络序

    int ret = bind(sock, (struct sockaddr*)&address, sizeof(address));
    assert(ret != 1);

    ret = listen(sock, 5);
    assert(ret != -1);

    sleep(20);
    struct sockaddr_in client;
    socklen_t client_addrlength = sizeof(client);
    int connfd = accept(sock, (struct sockaddr*)&client, &client_addrlength);
    if (connfd < 0){
        printf("error is: %d\n", errno);
    }else{
        char remote[INET_ADDRSTRLEN];
        printf("connected with ip: %s and port: %d\n", 
                inet_ntop(AF_INET, &client.sin_addr, remote, INET_ADDRSTRLEN), ntohs(client.sin_port));

        close(connfd);
    }

    close(sock); 
    return 0;
}









