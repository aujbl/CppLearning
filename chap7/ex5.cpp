#include <iostream>
#include <cstring>

using namespace std;
unsigned long recur(int n);

int main()
{
    int n = 0;
    cout << "enter a number.\n";
    while ((cin >> n) && (n >= 0))
        cout << n << "! = " << recur(n) << "\nenter next num.\n";
    cout << "enter a wrong num.\n";

    return 0;
}

unsigned long recur(int n)
{
    if (n == 0)
        return 1;
    else
        return n * recur(n - 1);
}