#include <iostream>

using namespace std;

class A {
    int x;
    public:
        A(int aa){
            x = aa;
            cout << "Constructing A" << endl;
        }
        ~A() { cout << "Destructing A" << endl; }
};

class B : public A{
    public:
        B(int x) : A(x) { cout << "Constructing B" << endl; }
};

class C : public B{
    public:
        C(int y) : B(y) { cout << "Constructing C" << endl; }
};

int main(int argc, char const *argv[])
{
    // 当同时存在直接基类和间接基类时，每个派生类只负责其直接基类的构造
    C c(1);

    // system("read -p 'Press Enter to continue...' var");
    return 0;
}
