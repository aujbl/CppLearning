#include <iostream>
#include <cstring>
#include <array>
using namespace std;

int main()
{
    array<float, 3> grades;
    cout << "grade one: \n";
    cin >> grades[0];
    cout << "grade two: \n";
    cin >> grades[1];
    cout << "grade three: \n";
    cin >> grades[2];

    cout << "avg grade: " << (grades[0] + grades[1] + grades[2])/3 << endl;
    return 0;
}
