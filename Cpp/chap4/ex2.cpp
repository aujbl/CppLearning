#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string name, dessert;
    cout << "name?\n";
    // cin >> name;   //中间不能有空格
    getline(cin, name);
    cout << "dessert?\n";
    // cin >> dessert;
    getline(cin, dessert);
    cout << "I have " << dessert << " for you. " << name << endl;

    return 0;
}
