#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const char *month[12] = {
        "month 1",
        "month 2",
        "month 3",
        "month 4",
        "month 5",
        "month 6",
        "month 7",
        "month 8",
        "month 9",
        "month 10",
        "month 11",
        "month 12",
    };
    int nums[12];
    for (int i = 0; i < 12;++i)
    {
        cout << month[i] << ", enter sales: "<< endl;
        cin >> nums[i];
    }
    int ans = 0;
    for (int i = 0; i < 12;++i)
        ans += nums[i];
    cout << "total sales = " << ans << endl;

    return 0;
}
