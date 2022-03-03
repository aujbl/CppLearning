#include <iostream>

using namespace std;

class B{
    private:
        int i;
    protected:
        int j;
    public:
        int k;
};

class D : public B{
    public:
        void f(){
            i = 1;              // 派生类不可访问基类的私有成员
            j = 2;              // 派生类可以访问基类的保护成员
            k = 3;
        }
};

int main(int argc, char const *argv[])
{
    B b;
    b.i = 1;                    // 类的使用者不能访问私有成员
    b.j = 2;                    // 类的使用者不能访问保护成员
    b.k = 3;

    // system("read -p 'Press Enter to continue...' var");
    return 0;
}
