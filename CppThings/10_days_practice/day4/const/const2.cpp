#include <iostream>

using namespace std;
void display(const double &r);

class A
{
    public:
        A(int i, int j) { x = i;
            y = j;
        }
    private:
        int x, y;
};

int main(int argc, char const *argv[])
{
    double d(9.5);
    display(d);

    // 常类型的对象必须初始化，且不能被更新
    // 
    A const a(3, 4);        // a是常对象，不能被更新

    system("read -p 'Press Enter to continue...' var");
    return 0;
}

// 常引用做形参，在函数中不能更新 r所引用的对象
void display(const double &r)
{
    cout << r << endl;
}