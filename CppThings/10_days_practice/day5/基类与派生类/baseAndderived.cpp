#include <iostream>

using namespace std;

class A{
    int a;
    public:
        void setA(int x) { a = x; }
        int getA() { return a; }
};

class B : public A{
    int b;
    public:
        void setB(int x) { b = x; }
        int getB() { return b; }
};

void f1(A a, int x){
    a.setA(x);
}

void f2(A *pA, int x){
    pA->setA(x);
}

void f3(A &rA, int x){
    rA.setA(x);
}

int main(int argc, char const *argv[])
{
    A a1, *pA;
    B b1, *pB;
    a1.setA(1);
    b1.setA(2);

    // 派生类对象赋给基类对象
    a1 = b1;
    cout << a1.getA() << endl;                      // 1
    cout << b1.getA() << endl;                      // 2

    a1.setA(10);
    cout << a1.getA() << endl;                      // 10
    cout << b1.getA() << endl;                      // 2

    // 把派生对象的地址赋给基类指针
    pA = &b1;
    pA->setA(20);               
    cout << pA->getA() << endl;                     // 20
    cout << b1.getA() << endl;                      // 20

    // 用派生类对象初始化基类对象的引用
    A &ra = b1;
    ra.setA(30);
    cout << "pA: " << pA->getA() << endl;           // 30
    cout << "ra: " << ra.getA() << endl;            // 30
    cout << "b1: " << b1.getA() << endl;            // 30

    b1.setA(7);
    cout << b1.getA() << endl;                      // 7

    f1(b1, 100);
    cout << "after f1: " << endl;                   // 
    cout << b1.getA() << endl;                      // 7

    f2(&b1, 200);
    cout << b1.getA() << endl;                      // 200

    f3(b1, 300);
    cout << b1.getA() << endl;                      // 300

    // system("read -p 'Press Enter to continue...' var");
    return 0;
}
