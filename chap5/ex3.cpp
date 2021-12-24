#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int num = 1;
    int ans = 0;
    while (num)
    {
        cout << "enter a num, enter 0 to break\n";
        cin >> num;
        ans += num;
        cout << "sum of nums = " << ans << endl;
    }
    cout << "end.\n";

    return 0;
}
