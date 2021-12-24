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
   };
   pizza *p1 = new pizza;

   cout << "radius: \n";
   cin >> p1->radius;
   cout << "please enter company's name: \n";
   cin.get();                    //先获取半径，会在输入序列留下一个'\n'(确定时的回车键),导致getline直接跳过
   getline(cin, p1->name);
   cout << "weight: \n";
   cin >> p1->weight;
   cout << "p1 message:\n";
   cout << "name: " << p1->name << endl;
   cout << "radius: " << p1->radius << endl;
   cout << "weight: " << p1->weight << endl;

   return 0;
}