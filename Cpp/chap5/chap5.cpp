#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

int main()
{
    // int x = 5;
    // int y = x++;
    // cout << "x++: " << x << " y: " << y << endl;        //x++: 6 y: 5
    // int z = 5;
    // y = ++z;
    // cout << "++z: " << z << " y: " << y << endl;        //++z: 6 y: 6

    // int guests = 0;
    // while(guests++ < 10)
    // {
    //     cout << guests << "  ";
    // }
    // cout << endl;

    // int n1, n2;
    // n1 = n2 = 0;
    // cout << "n++: ";
    // for (int n = 0; n < 10; n1 = n++)
    //     cout << n1;
    // cout << endl;
    // cout << "++n: ";
    // for (int n = 0; n < 10; n2 = ++n)
    //     cout << n2;
    // cout << endl;

    // double arr[5]{21.1, 32.8, 23.4, 45.2, 37.4};
    // double *pt = arr; 
    // cout << "pt: " << pt <<" *pt: " << *pt << endl; // pt: 0x61fdd0 *pt: 21.1
    // ++pt;
    // cout << "pt: " << pt <<" *pt: " << *pt << endl; // pt: 0x61fdd8 *pt: 32.8
    // double x = *++pt;
    // cout << "x: " << x << endl;                     // x: 23.4
    // cout << "pt: " << pt <<" *pt: " << *pt << endl; // pt: 0x61fde0 *pt: 23.4
    // ++*pt;
    // cout << "pt: " << pt <<" *pt: " << *pt << endl; // pt: 0x61fde0 *pt: 24.4
    // (*pt)++;
    // cout << "pt: " << pt <<" *pt: " << *pt << endl; // pt: 0x61fde0 *pt: 25.4
    // x = *pt++;
    // cout << "x: " << x << endl;                     // x: 25.4
    // cout << "pt: " << pt <<" *pt: " << *pt << endl; // pt: 0x61fde8 *pt: 45.2

    // int cats;
    // cats = 17, 240;
    // cout << "cats: " << cats << endl;               //cats: 17
    // (cats = 17), 240;
    // cout << "cats: " << cats << endl;               //cats: 17
    // cats = (17, 240);
    // cout << "cats: " << cats << endl;               //cats: 240
    // cats = (240, 17);
    // cout << "cats: " << cats << endl;               //cats: 17

    // #define float_pt float *
    // float a = 0.;
    // float_pt pa = &a, pb = 1;
    // cout << "pa: " << pa << " pb: " << pb << endl;

    // double prices[5] = {4.99, 10.99, 6.87, 7.99, 8.49};
    // for (double x : prices)
    //     cout << "x: " << x << ' ';//x: 4.99 x: 10.99 x: 6.87 x: 7.99 x: 8.49 
    // cout << '\n';
    // for (double &x : prices)
    //     cout << "x: " << x << ' ';//x: 4.99 x: 10.99 x: 6.87 x: 7.99 x: 8.49

    // char ch;
    // int count = 0;
    // cout << "enter '#' to quit.\n";
    // cin >> ch;
    // while (ch != '#')
    // {
    //     cout << ch;
    //     ++count;
    //     cin >> ch;
    // }
    // cout << "\ncount: " << count << endl;

    char ch;
    ch = cin.get();
    cout << "ch = cin.get(): " << ch << endl;

    cin.get();
    ch = cin.get(ch);
    cout << "cin.get(): " << ch << endl;


    return 0;
}









