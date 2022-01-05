#include <iostream>
#include <cstring>

using namespace std;
struct chaff
{
    char dross[20];
    int slag;
};

int main()
{
    char *buffer = new char[100];
    chaff *pt = new (buffer) chaff;
    strcpy(pt->dross, "chaff");
    pt->slag = 1;
    cout << "dross: " << pt->dross << endl;
    cout << "slag: " << pt->slag << endl;

    return 0;
}
