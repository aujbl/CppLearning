#include <iostream>

using namespace std;

class Base{
    private:
        int x;
    public:
        Base(int a){
            x = a;
            cout << "Base constructor x=" << x << endl;
        }
        ~Base() { cout << "Base destructor..." << endl; }
};

class Derived:public Base{
    private:
        int y;
    public:
        Derived(int a, int b):Base(a){
            y = b;
            cout << "Derived constructor y=" << y << endl;
        }
        ~Derived() { cout << "Derived destructor..." << endl; }
};

int
main(int argc, char const *argv[])
{
    Derived d(1, 2);

    system("read -p 'Press Enter to continue...' var");
    return 0;
}
