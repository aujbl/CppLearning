#include <stdio.h>
#include <unistd.h>

#define BUF_SIZE 30
// void error_handling(char *message);

int main(int argc, char *argv[])
{
    int fds[2];
    char str[] = "Who are you?";
    char buf[BUF_SIZE];
    pid_t pid;

    pipe(fds);
    pid = fork();
    if (pid == 0)
    {
        write(fds[1], str, sizeof(str));
    }
    else
    {
        read(fds[0], buf, BUF_SIZE);
        puts(buf);
    }

    return 0;
}


// void error_handling(char *message)
// {
//     fputs(message, stderr);
//     fputc('\n', stderr);
//     exit(1);
// }