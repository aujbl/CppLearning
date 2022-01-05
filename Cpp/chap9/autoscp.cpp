#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int x = 2021;
    cout << "main x = " << x << endl;
    {
        cout << "block x = " << x << endl;
        int x = 1202;               //hide main x
        cout << "new block x = " << x << endl;
    }
    cout << "after block x = " << x << endl;

    return 0;
}
