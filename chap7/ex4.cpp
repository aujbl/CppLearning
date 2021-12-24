#include <iostream>
#include <cstring>

using namespace std;
long double pro(unsigned numbers, unsigned picks);

int main()
{
    double choice, total, s_choice, s_total;
    cout << "enter the total nums, choice, s total, s choice: \n";
    while ((cin >> total >> choice >> s_total >> s_choice) && (choice <= total) && (s_choice <= s_total))
    {
        cout << "pro = ";
        cout << pro(total, choice) * pro(s_total, s_choice) << endl;
        cout << "enter new num or q to quit.\n";
    }

    return 0;
}

long double pro(unsigned numbers, unsigned picks)
{
    long double result = 1.0;
    long double n;
    unsigned p;
    for (n = numbers, p = picks; p > 0; --n, --p)
        result *= (n / p);
    return 1 / result;
}
