#include <iostream>

using namespace std;
int f(int, int);

int main(int argc, char const *argv[])
{
    cout << "Enter n and k: ";
    int n, k;
    cin >> n;
    cin >> k;
    cout << f(n, k) << endl;

    system("read -p 'Press Enter to continue...' var");
    return 0;
}

// 组合数：Cnk (select k items from n items.)
int f(int n, int k)
{
    if (n < k)
    {
        cout << "n should be >= k, exchange n and k.\n";
        int tmp = k;
        k = n;
        n = tmp;
    }
    if ((n == k) || (k == 0))
        return 1;
    else
        return f(n - 1, k - 1) + f(n - 1, k);
}
