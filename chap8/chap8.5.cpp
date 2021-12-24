#include <iostream>
#include <cstring>

using namespace std;
long indeed(int n);

int main()
{
    // int n = 3;
    // cout << typeid(indeed(n)).name() << endl;
    int n = 0;
    cout << typeid((n)).name() << endl;

    float m = 5.5f;
    float &rm = m;
    cout << typeid(rm).name() << endl;

    decltype((m)) v3 = m;
    cout << typeid(v3).name() << endl;

    return 0;
}

long indeed(int n)
{
    return long(n);
}