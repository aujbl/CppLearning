#include <iostream>

using namespace std;

class A{
    public:
        A() { cout << "Constructing A" << endl; }
        ~A() { cout << "Destruting A" << endl; }
};

class B{
    public:
        B() { cout << "Constructing B" << endl; }
        ~B(){ cout << "Destruting B" << endl; }
};

class C{
    public:
        C() { cout << "Construting C" << endl; }
        ~C() { cout << "Destruting C" << endl; }
        B b;
        A a;
};

/*
先构造成员(有基类时先构造基类)
再构造自身（调用构造函数）
先构造后析构
*/

/*
执行结果：
Constructing B
Constructing A
Constructing C
Destructing C
Destructing A
Destructing B
*/

int main(int argc, char const *argv[])
{
    C c;

    system("read -p 'Press Enter to continue...' var");
    return 0;
}
