#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 3

int main()
{
    int fd1, fd2;
    int len;
    char buf[BUF_SIZE];

    fd1 = open("news.txt", O_RDONLY);
    fd2 = open("cpy.txt", O_WRONLY | O_CREAT | O_TRUNC);

    while ((len=read(fd1, buf, sizeof(buf))) > 0)
    {
        /*系统提供的read & write函数，为提供缓冲，发送数据需要花费很长时间*/
        write(fd2, buf, len);
    }
    close(fd1);
    close(fd2);
    return 0;
}