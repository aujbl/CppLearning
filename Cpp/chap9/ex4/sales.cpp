#include "sales.h"
#include <iostream>
using std::cout;
using std::endl;

namespace SLAES
{

    void setSales(Sales &s, const double ar[], int n)
    {
        n = n > 4 ? 4 : n;
        double sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += ar[i];
            s.sales[i] = ar[i];
            if (ar[i] > s.max)
                s.max = ar[i];
            if (ar[i] < s.min)
                s.min = ar[i];
        }
        s.average = sum / n;
    }


    void setSales(Sales &s)
    {

    }


    void showSales(const Sales &s)
    {
        cout << "QUARTER:";
        for (int i = 0; i < 4; ++i)
        {
            cout << "\t" << s.sales[i];
        }
        cout << endl;
        cout << "average: " << s.average << endl;
        cout << "max: " << s.max << endl;
        cout << "min: " << s.min << endl;
    }

}


