#include <iostream>

using namespace std;
inline double CalArea(double);

int main(int argc, char const *argv[])
{
    double r(1.0);
    double area;
    area = CalArea(r);
    cout << "area: " << area << endl;
    system("read -p 'Press Enter to continue...' var");
    return 0;
}

inline double CalArea(double radius)
{
    return 3.14 * radius * radius;
}
