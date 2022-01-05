#include <iostream>
#include <cstring>
struct CandyBar
{
    char * brand;
    double weight;
    int calori;
};

using namespace std;
void setCandyBar(CandyBar &bar, char *name="Millennium Munch", double w=2.85, int c=350);
void showCandyBar(const CandyBar &bar);

int main()
{
    CandyBar b;
    setCandyBar(b);
    showCandyBar(b);

    return 0;
}

void setCandyBar(CandyBar &bar, char * name, double w, int c)
{
    bar.brand = name;
    bar.weight = w;
    bar.calori = c;
}

void showCandyBar(const CandyBar &bar)
{
    cout << "bar's name: " << bar.brand << endl;
    cout << "weight: " << bar.weight << endl;
    cout << "calori: " << bar.calori << endl;
}

