#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    struct car
    {
        string man_name;
        int man_year;
    };
    int num_cars = 0;
    cout << "how many cars do you have?\n";
    cin >> num_cars;
    car* cars = new car[num_cars];
    for (int i = 0; i < num_cars; ++i)
    {
        cout << "enter car" << i+1 << "'s man_name:\n";
        cin >> cars[i].man_name;
        cin.get();
        cout << "enter car" << i+1 << "'s man_year:\n";
        cin >> cars[i].man_year;
    };
    for (int i = 0; i < num_cars; ++i)
    {
        cout << "car " << i+1 << endl;
        cout << "car" << i+1 << "'s man_name: " << cars[i].man_name << endl;
        cout << "car" << i+1 << "'s man_year: " << cars[i].man_year << endl;
    }

        return 0;
}
