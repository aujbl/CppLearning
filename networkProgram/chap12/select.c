/*
将多个文件描述符集中到一起统一监视
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30
void error_handling(char *message);

int main(int argc, char *argv[])
{
    fd_set reads, temps;
    int result, str_len;
    char buf[BUF_SIZE];
    struct timeval timeout;

    FD_ZERO(&reads);
    FD_SET(0, &reads);

    while (1)
    {
        temps = reads;
        timeout.tv_sec = 2;
        timeout.tv_usec = 0;
        result = select(1, &temps, 0, 0, &timeout);
        // printf("result: %d \n", result);
        if (result == -1)
        {
            puts("select() error.");
            break;
        }
        else if (result == 0)
        {
            puts("time out.");
        }
        else
        {
            if (FD_ISSET(0, &temps))
            {
                str_len = read(0, buf, BUF_SIZE);
                buf[str_len] = 0;
                printf("message from console: %s \n", buf);
            }
        }
    }


    return 0;
}


void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}