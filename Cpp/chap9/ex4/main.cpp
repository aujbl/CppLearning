#include "sales.h"
#include <iostream>
#include <cstring>

using namespace std;
using namespace SLAES;

int main()
{
    double ar[5] = {1, 2, 3, 4, 5};
    Sales s;
    setSales(s, ar, 5);
    showSales(s);

    return 0;
}
