#include <iostream>
#include <cstring>

using namespace std;

int main()
{
   struct pizza
   {
       string name;
       float radius;
       float weight;
   } p1;

   cout << "please enter name: \n";
   getline(cin, p1.name);
   cout << "radius: \n";
   cin >> p1.radius;
   cout << "weight: \n";
   cin >> p1.weight;
   cout << "p1 message:\n";
   cout << "name: " << p1.name << endl;
   cout << "radius: " << p1.radius << endl;
   cout << "weight: " << p1.weight << endl;

   return 0;
}
