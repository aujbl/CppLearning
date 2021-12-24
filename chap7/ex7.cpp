#include <iostream>
#include <cstring>

double *fill_array(double ar[], int limit);
void show_array(double *begin, double *end);
void revalue(double r, double *begin, double *end);
using namespace std;
const int MAX = 5;

int main()
{
    double pro[MAX];
    double *p = fill_array(pro, MAX);
    show_array(pro, p);
    cout << "enter a factor:\n";
    double factor;
    while (!(cin >> factor))
    {
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cout << "bad input, please enter a new factor.\n";
    }
    revalue(factor, pro, p);
    cout << "show revalue array.\n";
    show_array(pro, p);

    return 0;
}

double *fill_array(double ar[], int limit)
{
    double tmp;
    for (int i = 0; i < limit; ++i)
    {
        cout << "enter value: " << i + 1 << endl;
        cin >> tmp;
        if (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "bad input, end.\n";
            break;
        }
        else if (tmp < 0)
            break;
        *ar++ = tmp;
    }
    return ar;
}

void show_array(double *begin, double *end)
{
    int i = 1;
    while (begin != end)
        cout << "pro " << i << " = " << *begin++ << endl;
}

void revalue(double r, double *begin, double *end)
{
    while (begin != end)   
        *begin++ *= r;
}