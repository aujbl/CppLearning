#include <iostream>
#include <cstring>

using namespace std;
template <typename T>
T max5(const T t[]);

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    cout << "int max5: " << max5(a) << endl;
    double b[5] = {1., 3., 56., 7., 9.};
    cout << "double max5: " << max5(b) << endl;

    return 0;
}

template <typename T>
T max5(const T t[])
{
    T temp;
    temp = t[0];
    for (int i = 1; i < 5; ++i)
    {
        temp = temp < t[i] ? t[i] : temp;
    }
    return temp;
}
