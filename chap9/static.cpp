#include <iostream>
#include <cstring>

using namespace std;
void def_static();

int main()
{
    static int s = 1;
    def_static();
    cout << "s = " << s << endl;
    def_static();

    return 0;
}


void def_static()
{
    static int s = 10;
    s += 10;
    cout << "static s = " << s << endl;
}