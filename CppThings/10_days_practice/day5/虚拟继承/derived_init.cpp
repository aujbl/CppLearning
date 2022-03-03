#include <iostream>

using namespace std;

class A{
    int a;
    public:
        A(int x){
            a = x;
            cout << "Virtual Bass A..." << endl;
        }
};

class B: virtual public A{
    public:
        B(int i) : A(i) { cout << "Virtual Bass B..." << endl; }
};

class C:virtual public A{
    int x;
    public:
        C(int i):A(i){
            cout << "Constructing C..." << endl;
            x = i;
        }
};

class ABC:public C, public B{
    public:
        ABC(int i, int j, int k):C(i), B(j), A(i){
            cout << "Constructing ABC..." << endl;
        }
};

int main(int argc, char const *argv[])
{
    ABC obj(1, 2, 3);
    

    // system("read -p 'Press Enter to continue...' var");
    return 0;
}
