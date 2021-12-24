#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int a = 1;
    int *pt = &a;
    *pt = 2;
    // int a = 1;
    // pt = a;
    
    cout << "add of a：" << &a << endl;
    cout << "add of pt: " << pt << endl;
    cout << *pt;

    return 0;
}
