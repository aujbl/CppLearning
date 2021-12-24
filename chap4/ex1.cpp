#include <iostream>

int main(){
    using namespace std;
    char f_name[20];
    char l_name[20];
    char grade;
    int age;
    cout << "What is your first name?\n";
    cin.getline(f_name, 20);
    cout << "What is your last name?\n";
    cin.getline(l_name, 20);
    cout << "grade.\n";
    cin >> grade;
    cout << "What is your age?\n";
    cin >> age;
    cout << "Name: " << l_name << ',' << f_name << endl;
    cout << "Grade: " << char(grade + 1) << endl;
    cout << "Age: " << age << endl;
    return 0;
}