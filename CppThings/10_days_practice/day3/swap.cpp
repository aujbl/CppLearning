#include <iostream>

using namespace std;
void swap(int &, int &);

int main(int argc, char const *argv[])
{
    int x1(5);
    int x2(7);
    swap(x1, x2);
    cout << x1 << " " << x2 << endl;

    system("read -p 'Press Enter to continue...' var");
    return 0;
}

void swap(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}
