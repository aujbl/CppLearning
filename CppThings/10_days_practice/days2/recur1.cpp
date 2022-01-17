#include <iostream>

using namespace std;
int f(int);

int main(int argc, char const *argv[])
{
    cout << "Enter a num: ";
    int x;
    cin >> x;
    cout << f(x) << endl;

    system("read -p 'Press Enter to continue...' var");
    return 0;
}

// 阶乘
int f(int n)
{
    if(n)
        return n * f(n - 1);
    else
        return 1;
}
