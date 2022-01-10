#include <stdio.h>

int main()
{
    // x = ~x << 24;

    // while (1)
    // {
        int x = 0xffffffff;
        // scanf("%d ", &x);
        printf("max: %d \n", x);
        printf("result: %d \n", ((x & 0xAA) & ((x>>8)&0xAA) & ((x>>16)&0xAA) & ((x>>24)&0xAA)) & 1);

    //     x += 1;
    //     printf("max: %d \n", x);
    //     printf("result: %d \n", !((x + 1) ^ (~x)));
    //     break;
    // }
    // for (int i = 0; i == __INT32_MAX__; i++)
    // {
    //     if (!((i+1) ^ (~i)))
    //         printf("max num: %d \t", i);
    //     // if ((i % 10000) == 0)
    //     //     printf(".");
    // }

        return 0;
}