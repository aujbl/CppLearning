#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string chs;
    cout << "enter: \n";
    cin >> chs;
    int cnt = 0;
    while (chs != "done")
    {
        cnt += 1;
        cin >> chs;
    }
    cout << "total words: " << cnt << endl;

    return 0;
}
