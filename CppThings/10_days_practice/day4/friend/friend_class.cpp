#include <iostream>

using namespace std;

/*
如果声明B类是A类的友元，B类的成员函数就可以访问A类的私有和保护数据，
但A类的成员函数却不能访问B类的私有、保护数据。
*/

class A
{
    friend class B;     // B是A的友元类，可以访问A类的私有数据成员x
    public:
        void Display(){
            cout << x << endl;
        }
    private:
        int x;
};

class B
{
    public:
        void Set(int i);
        void Display();
    private:
        A a;
};

void B::Set(int i)
{
    a.x = i;        // 访问A类的私有数据成员
}
void B::Display()
{
    a.Display();
}

int main(int argc, char const *argv[])
{
    B b;
    b.Set(10);
    b.Display();

    system("read -p 'Press Enter to continue...' var");
    return 0;
}
