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

   CandyBar *p = new CandyBar[3];
   p[0] = {"b1", 1.0, 100};
   p[1] = {"b2", 2.0, 200};
   p[2] = {"b3", 3.0, 300};

   cout << "b: " << p[0].brand << " w: "
        << p[0].weight << " c: " << p[0].calorie << endl;
   cout << "b: " << p[1].brand << " w: "
        << p[1].weight << " c: " << p[1].calorie << endl;
   cout << "b: " << p[2].brand << " w: "
        << p[2].weight << " c: " << p[2].calorie << endl;

   delete[] p; //remember delete
   return 0;
}