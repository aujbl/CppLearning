#include <iostream>
#include <cstring>

using namespace std;
int grade(double *p);
void show_arr(const double *p, int size);
void avg_arr(const double *p, int size);

int main()
{
    double golf[10];
    int size = grade(golf);
    show_arr(golf, size);
    avg_arr(golf, size);

    return 0;
}

int grade(double *p)
{
    cout << "Please enter grade.\n";
    int i = 0;
    while ((i < 10) && (cin >> p[i++]))
        cout << " record num i: " << i << "\tnext num:\n" << endl;
    cout << "end input.\n";
    return i;
}

void show_arr(const double *p, int size)
{
    for (int i = 0; i < size; ++i)
        cout << p[i] << "\t";
    cout << endl;
}

void avg_arr(const double *p, int size)
{
    double avg;
    for (int i = 0; i < size; ++i)
    {
        avg += p[i];
    }
    cout << "avg = " << avg / size << endl;
}