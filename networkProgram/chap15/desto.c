#include <stdio.h>
#include <fcntl.h>

int main()
{
    FILE *fp;
    int fd = open("data.dat", O_WRONLY | O_CREAT | O_TRUNC);
    if(fd == -1)
    {
        fputs("file open error.\n", stdout);
        return -1;
    }
    /*fdopen可以将文件描述符转换为FILE指针，通过该指针可以调用标准I/O函数*/
    fp = fdopen(fd, "w");
    fputs("Network C programming \n", fp);
    fclose(fp);
    return 0;
}