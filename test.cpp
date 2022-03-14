#include <iostream>
using namespace std;

int main(){
    int a;
    const int b = 2;
    int c = 3;

    const int *p = &a;
    int const *p1 = &b;
    *p1 = 3;
    
    cout << *p1 << endl;

    cout << *p1 << endl;

    cout << *p << endl;

    a = 2;
    p = &c;

    cout << *p << endl;

    int * const p2 = &a;
    p2 = &b;

    return 0;
}
