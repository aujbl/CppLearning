#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int num;
    cout << "enter a num:\n";
    cin >> num;
    for (int i = 0; i < num; ++i)
    {
        for (int j = 0; j < num-i-1; ++j)
        {
            cout << '.';
        }
        for (int k = 0; k < i+1; ++k)
            cout << '*';
        cout << endl;
    }

        return 0;
}
