#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char *message);
int main(int argc, char *argv[])
{
    int sock;
    int snd_buf=1024, rcv_buf=1024;
    int state;
    socklen_t len;

    sock = socket(PF_INET, SOCK_STREAM, 0);

    // // len = sizeof(snd_buf);
    state = setsockopt(sock, SOL_SOCKET, SO_SNDBUF, (void *)&snd_buf, sizeof(snd_buf));
    if (state)
        error_handling("getsockopt error.");

    // // len = sizeof(rcv_buf);
    state = setsockopt(sock, SOL_SOCKET, SO_RCVBUF, (void *)&rcv_buf, sizeof(rcv_buf));
    if (state)
        error_handling("getsockopt error.");

    len = sizeof(snd_buf);
    state = getsockopt(sock, SOL_SOCKET, SO_SNDBUF, (void *)&snd_buf, &len);
    if (state)
        error_handling("getsockopt error.");

    len = sizeof(rcv_buf);
    state = getsockopt(sock, SOL_SOCKET, SO_RCVBUF, (void *)&rcv_buf, &len);
    if (state)
        error_handling("getsockopt error.");

    printf("Input buffer size: %d \n", rcv_buf);
    printf("Output buffer size: %d \n", snd_buf);

    return 0;
}


void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}