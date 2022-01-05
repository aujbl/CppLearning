#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int sales[3][12];
    int total_sale = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            cout << "year: " << i+1 << " month: " << j+1 << endl;
            cin >> sales[i][j];
            total_sale += sales[i][j];
        }
    }
    cout << "total sales = " << total_sale << endl;

    return 0;
}
