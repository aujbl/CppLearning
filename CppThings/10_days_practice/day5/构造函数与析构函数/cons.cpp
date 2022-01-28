#include <iostream>

using namespace std;

class A
{
private:
    int x;

public:
    A(int i=0){
    x = i;
    cout << "A-----" << x << endl;
};
    // ~A();
};

class B
{
private:
    int y;

public:
    B(int i);
    // ~B();
};

B::B(int i)
{
    y = i;
    cout << "B---------" << y << endl;
};

class C
{
private:
    int z;

public:
    C(int i);
    // ~C();
};

C::C(int i)
{
    z = i;
    cout << "C--------" << z << endl;
};

class D:public B
{
private:
    /* data */
public:
    C c1, c2;
    A *a1 = new A(10);
    A a0, a4;
    D(/* args */) : a4(4), c2(2), c1(1), B(1){
        cout << "D--------" << endl;
    };
    // ~D();
};

/*
B -> C -> C -> A -> A -> A -> D
*/

int main(int argc, char const *argv[])
{
    D d;

    system("read -p 'Press Enter to continue...' var");
    return 0;
}
