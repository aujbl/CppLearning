#include <iostream>

using namespace std;

class Base{
    int x;
    public:
        void setx(int n) { x = n; }
        int getx() { return x; }
        void showx() { cout << x << endl; }
};

class derived: private Base{
    int y;
    public:
        void sety(int n) { y = n; }
        void sety() { y = getx(); }
        void showy() { cout << y << endl; }
};

int main(int argc, char const *argv[])
{
    derived obj;
    obj.setx(10);           // 私有，无法访问
    obj.sety(20);
    obj.showx();            // 私有
    obj.showy();

    // system("read -p 'Press Enter to continue...' var");
    return 0;
}
