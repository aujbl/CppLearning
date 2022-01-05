#include <iostream>
#include <cstring>
using namespace std;

int main()
{
   struct CandyBar
   {
       string brand;
       float weight;
       int calorie;
   };

   CandyBar snacks[3]{
       {"b1", 1.0, 100}, //, not;
       {"b2", 2.0, 200},
       {"b3", 3.0, 300},
   };

   cout << "b: " << snacks[0].brand << " w: "
        << snacks[0].weight << " c: " << snacks[0].calorie << endl;
    cout << "b: " << snacks[1].brand << " w: "
        << snacks[1].weight << " c: " << snacks[1].calorie << endl;
    cout << "b: " << snacks[2].brand << " w: "
        << snacks[2].weight << " c: " << snacks[2].calorie << endl;

   return 0;
}
