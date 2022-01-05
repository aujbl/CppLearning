#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    double income, reven;
    cout << "Enter your income.\n";
    while ((cin >> income))
    {
        if (income <= 5000)
            reven = 0;
        else if (income <= 15000)
            reven = (income - 5000) * 0.1;
        else if (income <= 35000)
            reven = 10000 * 0.1 + (income - 15000) * 0.15;
        else
            reven = 10000 * 0.1 + 20000 * 0.15 + (income - 35000) * 0.2;
        cout << "your reven = " << reven << endl;
        cout << "please enter new income:\n";
    }

    return 0;
}
