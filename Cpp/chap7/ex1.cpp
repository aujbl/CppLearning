#include <iostream>
#include <cstring>

using namespace std;
double harm(double, double);

int main()
{
    double x, y;
    cout << "enter two nums.\n";
    while (cin >> x >> y)
    {
        if ((x==0) || (y==0))
            break;
        cout << "harm = " << harm(x, y) << endl;
        cout << "enter two nums.\n";
    }
    cout << "end.\n";
    return 0;
}

double harm(double x, double y) 
{
    return 2.0 * x * y / (x + y);
}
