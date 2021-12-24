#include <iostream>
#include <cstring>
#include <array>

using namespace std;

int main()
{
    const int nums = 101;
    array<long double, nums> factorials;
    factorials[1] = factorials[0] = 1;
    cout << "0! = " << factorials[0] << endl;
    cout << "1! = " << factorials[1] << endl;
    for (int i = 2; i < nums; ++i)
    {
        factorials[i] = i * factorials[i - 1];
        cout << i << "! = " << factorials[i] << endl;
    }

        return 0;
}
