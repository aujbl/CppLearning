#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int line = 0;
    char ch;
    // while (cin.get(ch))
    // {
    //     if (ch == 'Q')
    //         break;
    //     if (ch != '\n')
    //         continue;
    //     line++;
    // }
    // cin.get(ch);
    // while ((ch != 'Q') and (ch == '\n'))   //wrong, 只能检测'\n'
    // {
    //     line++;
    //     cin.get(ch);
    // }

    cin.get(ch);
    while ((ch != 'Q'))   //wrong, 只能检测'\n'
    {
        if (ch == '\n')
            line++;
        cin.get(ch);
    }

    cout << "line: " << line << endl;

    return 0;
}
