#include <iostream>

using namespace std;

class base{
    int x;
    protected:
        int i = 0;
        int getx() { return x; }
    public:
        void setx(int n) { x = n; }
        void showx() { cout << x << endl; }
};

class Derived:protected base{
    int y;
    public:
        void sety(int n) { y = n;
            cout << i << endl;          // 派生类可以访问基类的保护成员
        }
        void sety() { y = getx(); }
        void showy() { cout << y << endl; }
};

int main(int argc, char const *argv[])
{
    Derived obj;
    // obj.setx(10);           // error
    obj.sety(20);
    // obj.showx();            // error
    obj.showy();

    // system("read -p 'Press Enter to continue...' var");
    return 0;
}
