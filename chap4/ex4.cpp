#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string f_name, l_name, name;
    cout << "Enter your first name: \n";
    getline(cin, f_name);
    cout << "Enter your last name: \n";
    getline(cin, l_name);
    name = f_name + ", " + l_name;
    cout << "name: " << name << endl;

    return 0;
}
