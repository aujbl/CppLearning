#include <iostream>
#include <cstring>

using namespace std;

int main()
{
   char f_name[10];
   char l_name[10];
   char name[25];
   cout << "Enter your first name: \n";
   cin.getline(f_name, 10);
   cout << "Enter your last name: \n";
   cin.getline(l_name, 10);
   strcat(name, f_name);
   strcat(name, ", ");
   strcat(name, l_name);
   cout << "name: " << name << endl;

   return 0;
}
