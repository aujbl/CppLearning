#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    cout << "enter: \n";
    char chs[20];
    cin >> chs;
    int cnt = 0;
    while (strcmp(chs, "done"))
    {
        cnt += 1;
        cin >> chs;
    }
    cout << "total words: " << cnt << endl;

    return 0;
}
