#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
    char ch;
    while (cin.get(ch) and (ch != '@'))
    {
        if (!(isdigit(ch)))
        {
            if (islower(ch))
                cout << char(toupper(ch)) << endl;
            else if(isupper(ch))
                cout << char(tolower(ch)) << endl;
            else
                cout << ch << endl;
        }
    }

    return 0;
}
