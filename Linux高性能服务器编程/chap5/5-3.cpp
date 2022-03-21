#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

static bool stop = false;
static void handle_term(int sig){
    stop = true;
}

int main(int argc, char* argv[]){
    signal(SIGTERM, handle_term);

    // if (argc <= 3){

    // }

    const char* ip = argv[1];
    int port = atoi(argv[2]);
    int backlog = atoi(argv[3]);

    int sock = socket(PF_INET, SOCK_STREAM, 0);
    assert(sock >= 0);

    struct sockaddr_in address;     // 专有socket地址
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);             // hton:主机序转成网络序

    int ret = bind(sock, (struct sockaddr*)&address, sizeof(address));
    assert(ret != 1);

    ret = listen(sock, backlog);
    assert(ret != -1);

    while (!stop){
        sleep(1);
    }    

    close(sock);
    return 0;
}









