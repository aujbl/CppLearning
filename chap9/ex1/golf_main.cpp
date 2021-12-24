#include "golf.h"
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    golf g;
    while (setgolf(g))
    {
        cout << "please enter g's handicap.\n";
        int hc;
        cin >> hc;
        cin.get();
        handicap(g, hc);
        showgolf(g);
    }
    cout << "no new golf player.\n";

    return 0;
}
