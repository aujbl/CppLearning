#include <iostream>

using namespace std;

class Application
{
    public:
        // 静态成员函数
        static void f();
        static void g();
    private:
        static int global;
};

int Application::global = 0;

// 静态成员函数只能引用属于该类的静态数据成员或静态成员函数
void Application::f()
{
    global = 5;
}

void Application::g()
{
    cout << global << endl;
}

int main(int argc, char const *argv[])
{
    // 通过类名和作用域操作符调用静态成员函数（无对象）
    Application::f();
    Application::g();
    system("read -p 'Press Enter to continue...' var");
    return 0;
}
