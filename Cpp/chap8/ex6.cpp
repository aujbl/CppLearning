#include <iostream>
#include <cstring>

using namespace std;
template <typename T>
T maxn(T t[], int n);
template <>
char* maxn(char* a[], int n);

int main()
{
    int a[6] = {1, 2, 3, 4, 5, 6};
    double b[4] = {1., 2., 3., 4.};
    char *c[3] = {"abcd", "efg", "hijklmn"};
    cout << maxn(a, 6) << endl;
    cout << maxn(b, 4) << endl;
    cout << maxn(c, 3) << endl;

    return 0;
}

template <typename T>
T maxn(T t[], int n)
{
    T temp = t[0];
    for (int i = 1; i < n; ++i)
        temp = temp < t[i] ? t[i] : temp;
    return temp;
}

//显式具体化
template <>
char* maxn<char*>(char* a[], int n)
{
    char * temp = a[0];
    int max_len = strlen(a[0]);
    for (int i = 1; i < n; ++i)
    {
        if (strlen(a[i]) > max_len)
        {
            temp = a[i];
            max_len = strlen(a[i]);
        }
    }
    return temp;
}
