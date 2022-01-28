#include <iostream>

using namespace std;

class A{
    public:
        A() { cout << "Constructing A" << endl; }
        ~A() { cout << "Destructing A" << endl; }
};

// 派生类可以没有构造函数
class B: public A{
    public:
        ~B() { cout << "Destructing B" << endl; }
};

int main(int argc, char const *argv[])
{
    B b;

    system("read -p 'Press Enter to continue...' var");
    return 0;
}
