#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vector.h"
#include <fstream>

int main()
{
    using namespace std;
    using VECTOR::Vector;

    ofstream walkfile;
    walkfile.open("walkfile.txt");

    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps;
    double target;
    double dstep;
    int times;
    int i = 0;
    cout << "Enter times: \n";
    cin >> times;
    while (i < times)
    {   
        if (i == 0){
            cout << "Enter target distance(q to quit).\n";
            cin >> target;
            cout << "Enter step length.\n";
            cin >> dstep;            
        }
        cout << "current time: " << i << endl;
        walkfile << "target distance: " << target;
        walkfile << ", step size: " << dstep << endl;
        result.rect_mode();
        walkfile << steps << ": (x, y) = (" << result.xval() << ", " << result.yval() << ") \n";
        
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            ++steps;
            result.rect_mode();
            result.polar_mode();
            walkfile << steps << ": (x, y) = (" << result.xval() << ", " << result.yval() << ") \n";
        }
        cout << "After " << steps << " steps, the subject has the following location: \n";
        cout << result << endl;
        walkfile << "After " << steps << " steps, the subject has the following location: \n";
        walkfile << result << endl;

        result.polar_mode();
        cout << "or \n" << result << endl;
        cout << "Average outward distance per step = " << result.magval() / steps << endl;
        walkfile << "or \n" << result << endl;
        walkfile << "Average outward distance per step = " << result.magval() / steps << endl;

        steps = 0;
        result.reset(0., 0.);
        cout << "Enter target distance (q to quit).\n";
        walkfile << "\n\n\n\n";

        ++i;

    }
    cout << "end.\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;

    walkfile.close();

    return 0;
}