#include <iostream>
#include <cstring>
struct debts
{
    char name[50];
    double amount;
};

using namespace std;
template <typename T>
double SumArray(T arr[], int n);
template <typename T>
double SumArray(T *arr[], int n);

int main()
{
    int things[6] = {13, 31, 103, 301, 310, 130};
    debts mr_E[3] =
        {
            {"Ima Wolfe", 2400.},
            {"Ura Foxe", 1300.},
            {"Iby Stout", 1800.}
        };
    double *pd[3];
    for (int i = 0; i < 3; ++i)
        pd[i] = &mr_E[i].amount;
    cout << "sum 1:\n"
         << SumArray(things, 6) << endl;
    cout << "sum 2:\n"
         << SumArray(pd, 3) << endl;

    return 0;
}

template <typename T>
double SumArray(T arr[], int n)
{
    cout << "template 1...\n";
    double sum = arr[0];
    for (int i = 1; i < n; ++i)
        sum += arr[i];
    return sum;
}

template <typename T>
double SumArray(T *arr[], int n)
{
    cout << "template 2...\n";
    double sum = 0;
    for (int i = 0; i < n; ++i)
        sum += *arr[i];
    return sum;
}