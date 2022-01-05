#include <iostream>
int main(){
    using namespace std;
    double *p3 = new double[3];
    p3[0] = 0;
    p3[1] = 1;
    p3[2] = 2;
    cout << "p3[1]: " << p3[1] << endl;
    cout << "*p3: " << *p3 << endl;

    double wages[3] {1000., 2000., 300.};
    double* pw = wages;         //
    double* ps = &wages[0];     //两者等价
    cout << "pw: " << pw << endl;
    cout << "ps: " << ps << endl;
    cout << "*pw: " << *pw << endl;
    cout << "*ps: " << *ps << endl;

    short tell[10];
    cout << "tell: " << tell << endl;
    cout << "&tell: " << &tell << endl;
    cout << "tell + 1: " << tell + 1 << endl;
    cout << "&tell + 1: " << &tell + 1 << endl;

    delete[] p3;
}