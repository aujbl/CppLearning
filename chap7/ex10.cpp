#include <iostream>
#include <cstring>

using namespace std;
double add(double a, double b);
double add1(double c, double d);
double calculate(double x, double y, double (*p_add)(double a, double b));

int main()
{
    // typedef double *padd(double x, double y);
    // padd p_add = add;
    // auto p_add = &add;
    double (*p_add)(double a, double b);
    double (*p_add1)(double c, double d);
    p_add = add;
    p_add1 = add1;
    // double (*p[2])(double a, double b) = {p_add, p_add1};
    double x, y;
    x = 1.1;
    y = 2.9;
    calculate(x, y, p_add);
    calculate(x, y, p_add1);
    // cout << "add result = " << calculate(x, y, p_add) << endl;

    return 0;
}

double add(double a, double b) 
{
    cout << "add: " << endl;
    // return double(int(a) + int(b));
    return 0;
}

double add1(double c, double d)
{
    cout << "add1: \n";
    // return double(int(c + d));
    return 0;
}

double calculate(double x, double y, double (*p)(double a, double b))
{
    (*p)(x, y);
    return 0;
}
