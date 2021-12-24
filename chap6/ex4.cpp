#include <iostream>
#include <cstring>

using namespace std;
void showmanu();
int strsize = 20;

int main()
{

   struct bop
   {
       char fullname[20] = "1";
       char title[20] = "2";
       char bopname[20] = "3";
       int preferance = 0;
   };

//    bop workers[3] =
//        {
//            {"m h t", "boss", "pony", 2},
//            {"z x l", "w boss", "dragon", 0},
//            {"l j b", "big boss", "bboss", 1}
//         };

    //  bop* workers = new bop[3];
    //  cout << "workers: " << workers << endl;
    //  cout << workers->fullname << endl;
     //   *(workers) = {"m h t", "boss", "pony", 2};
     //   workers[1] = {"z x l", "w boss", "dragon", 0};
     //   workers[2] = {"l j b", "big boss", "bboss", 1};

     char ch;
     showmanu();
     while ((cin.get(ch)) and (ch != 'q'))
     {
         switch (ch)
         {
         case 'a':
             for (int i = 0; i < 3; ++i)
                 cout << workers[i].fullname << endl;
             break;
         case 'b':
             for (int i = 0; i < 3; ++i)
                 cout << workers[i].title << endl;
             break;
         case 'c':
             for (int i = 0; i < 3; ++i)
                 cout << workers[i].bopname << endl;
             break;
         case 'd':
             int pre;
             for (int i = 0; i < 3; ++i)
             {
                 pre = workers[i].preferance;
                 switch (pre)
                 {
                 case 0:
                     cout << workers[i].fullname << endl;
                     break;
                 case 1:
                     cout << workers[i].title << endl;
                     break;
                 case 2:
                     cout << workers[i].bopname << endl;
                     break;
                 }
             }
             break;
         default:
             showmanu();
             continue;
         }
         cin.get();
         cout << "enter your choice.\n";
      }

    //   delete[] workers;
   return 0;
}

void showmanu()
{
    cout << "BOP report: \n";
    cout << "a) display by name.        b) display by title. \n";
    cout << "c) display by bopname.     d) display by preferance. \n";
    cout << "q) quit.\n";
    cout << "enter your choice.\n";
}