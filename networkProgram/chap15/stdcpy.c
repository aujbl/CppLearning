#include <stdio.h>
#define BUF_SIZE 3

int main()
{
    FILE *fp1;
    FILE *fp2;
    char buf[BUF_SIZE];

    fp1 = fopen("news.txt", "r");
    fp2 = fopen("cpy_std", "w");
    /*fputs & fgets可以完成基于缓冲的复制，速度大大提升*/
    while (fgets(buf, BUF_SIZE, fp1) != NULL)
        fputs(buf, fp2);
    fclose(fp1);
    fclose(fp2);
    return 0;
}