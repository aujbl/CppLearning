#include <iostream>
#include <cstring>
using namespace std;

int main()
{
   struct CandyBar{
       string brand;
       float weight;
       int calorie;
   };
   CandyBar snack{"Mocha Munch", 2.3, 350};
   cout << "snack brand: " << snack.brand << endl;
   cout << "snack weight: " << snack.weight << endl;
   cout << "snack calorie" << snack.calorie << endl;

   return 0;
}
