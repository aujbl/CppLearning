#include <iostream>
// #include <stdlib.h>
using namespace std;
int main(int argc, char const * argv[])
{
    int year;
    bool isLeapYear;
    cout << "Enter the year: ";
    cin >> year;
    isLeapYear = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    if (isLeapYear)
    {
        cout << year << " is a leap year" << endl;
    }
    else
    {
        cout << year << " is not a leap year" << endl;
    }
    // system("pause");
    system("read -p 'Press Enter to continue...' var");//
    return 0;
}