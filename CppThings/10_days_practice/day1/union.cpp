#include <iostream>
using namespace std;
union myun
{
    struct {
        int x;
        int y;
        int z;
    } u;
    int k;
} a;
int main()
{
    a.u.x =4;   //被改变
    a.u.y =5;   //未被改变
    a.u.z =6;   //未被改变
    a.k = 0;    //覆盖掉第一个int空间值
    printf("%d %d %d %d\n", a.u.x, a.u.y, a.u.z, a.k);
    printf("sizeof myun %ld\n", sizeof(myun));
    // system("pause");
    return 0;
}