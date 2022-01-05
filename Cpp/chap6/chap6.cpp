#include <iostream>
#include <cstring>

using namespace std;
void showmean();

int main()
{
    // char ch;
    // cout << "type: \n";
    // cin.get(ch);
    // while (ch != '.')
    // {
    //     if (ch == '\n')
    //         cout << ch;
    //     else
    //         // cout << ++ch;
    //         // cout << ch + 1;
    //         cout << char(ch + 1);
    //     cin.get(ch);
    // }
    // cout << "end.\n";

    // showmean();
    // int choice;
    // while (choice != 4)
    // {
    //     switch(choice)
    //     {
    //         case 1 :
    //             cout << "\a\n";
    //             break;
    //         case 2 :
    //             cout << "case 2 ...\n";
    //             break;
    //         case 3 :
    //             cout << "case 3 ...\n";
    //         default :
    //             cout << "other...\n";
    //     }
    //     showmean();
    //     cin >> choice;
    // }

    int golf[5];
    cout << "enter 5 numbers.\n";
    for (int i = 0; i < 5; ++i)
    {
        cout << "round " << i + 1 << ":\n";
        while (!(cin >> golf[i]))
        {
            cin.clear();
            char ch = cin.get();
            cout << "ch: ";
            while (ch != '\n')
            {
                cout << ch;
                ch = cin.get();
                continue;
            }
            cout << "\nPlease enter a number \n";
        }


    }
    double total = 0;
    for (int i = 0; i < 5; ++i)
    {
        total += golf[i];
    }
    cout << "avg = " << total / 5 << endl;

    return 0;
}

void showmean()
{
    cout << "Please enter 1, 2, 3 or 4\n"
            "1) alarm       2)...\n"
            "3)...          4)quit\n";
}


