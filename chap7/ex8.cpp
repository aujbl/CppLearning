#include <iostream>
#include <cstring>

void fill(double *e);
void fill(struct expense *e);
void show(const double *e);
void show(const struct expense *e);
using namespace std;
const char *seasons[4] = {"Spring", "Summer", "Fall", "Winter"};
struct expense
{
    double ex[4];
};

int main()
{
    // double expenses[4];
    // fill(expenses);
    // show(expenses);
    expense e;
    fill(&e);
    show(&e);

    return 0;
}

void fill(double *e)
{
    for (int i = 0; i < 4; ++i)
    {
        cout << "Season: " << seasons[i] << " expense.\n";
        cin >> e[i];
    }
}

void fill(struct expense *e)
{
    for (int i = 0; i < 4; ++i)
    {
        cout << "Season: " << seasons[i] << " expense.\n";
        cin >> e->ex[i];
    }
}

void show(const double *e)
{
    double total = 0;
    for (int i = 0; i < 4; ++i)
    {
        cout << "Season: " << seasons[i] << " expense = " << e[i] <<endl;
        total += e[i];
    }
    cout << "total expense = " << total <<endl;
}

void show(const struct expense *e)
{
    double total = 0;
    for (int i = 0; i < 4; ++i)
    {
        cout << "Season: " << seasons[i] << " expense = " << e->ex[i] <<endl;
        total += e->ex[i];
    }
    cout << "total expense = " << total <<endl;
}
