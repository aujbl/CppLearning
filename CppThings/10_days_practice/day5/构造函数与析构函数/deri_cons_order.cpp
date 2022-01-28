#include <iostream>

using namespace std;

class A{
    public:
        A() { cout << "Contructing A" << endl; }
        ~A() { cout << "Destructing A" << endl; }
};

class B{
    public:
        B() {cout << "Contructing B" << endl;}
        ~B(){cout << "Destructing B" << endl;}
};

class C{
    public:
        C() {cout << "Contructing C" << endl;}
        ~C(){cout << "Destructing C" << endl;}
};


// D需要使用C的构造函数，所以需要将C的构造函数设置为public
class D:public C
{
    public:
        D() {cout << "Contructing D" << endl;}
        ~D(){cout << "Destructing D" << endl;}
        B b;
        A a;
        C c;
};

/*
Contructing C
Contructing B
Contructing A
Contructing C
Contructing D

Destructing D
Destructing C
Destructing A
Destructing B
Destructing C
*/

/* 先基类构造函数 -> 成员 -> 构造函数*/

int main(int argc, char const *argv[])
{
    D d;

    system("read -p 'Press Enter to continue...' var");
    return 0;
}
