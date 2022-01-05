#include "coordin.h"
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: \n";
    while (cin >> rplace.x >> rplace.y)
    {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next place(or q to quit):\n";
    }
    cout << "end.\n";

    return 0;
}
