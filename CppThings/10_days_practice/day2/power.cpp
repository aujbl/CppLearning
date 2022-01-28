#include <iostream>

using namespace std;
double power(double, int);

int main(int argc, char const *argv[])
{
    int x;
    cin >> x;
    cout << "x: " << x << endl;
    int wei = 0;
    int sum = 0;
    int each, chu;
    /*二进制数转换为十进制*/
    for (int i = 0; i < 8; i++)
    {
        each = x % 10;
        chu = x / 10;
        sum += each * power(2, wei);
        x = chu;
        wei++;
        cout << "each: " << each << " chu: " << chu << " sum: ";
        cout<< sum << " x:" << x << " wei:" << wei << endl;
    }
    cout << sum << endl;

    system("read -p 'Press Enter to continue...' var");
    return 0;
}


double power(double x, int n)
{
    double val = 1.0;
    while (n--)
        val *= x;
    return val;
}
