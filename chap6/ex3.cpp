#include <iostream>
#include <cstring>

using namespace std;
void showmanu();

int main()
{
    showmanu();
    char ch;
    while ((cin.get(ch) and (ch != 'q')))
    {
        switch (ch)
        {
            case 'c':
                cout << "car.\n";
                break;
            case 't':
                cout << "tree.\n";
                break;
            case 'a':
                cout << "apple.\n";
                break;
            case 'g':
                cout << "game.\n";
                break;
            default:
                showmanu();
        }
        cin.get();
    }

    return 0;
}

void showmanu()
{
    cout << "Please enter one of the following choices:\n";
    cout << "c) car         t) tree\n";
    cout << "a) apple       g) game\n";
    cout << "q) quit\n";
}
