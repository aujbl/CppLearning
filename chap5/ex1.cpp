#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int i, j;
    cout << "enter two nums: \n";
    cin >> i;
    cin.get();
    cin >> j;
    int ans = 0;
    while (i <= j)
    {
        ans += i;
        ++i;
    }
    cout << "sum of i to j: " << ans << endl;

    return 0;
}
