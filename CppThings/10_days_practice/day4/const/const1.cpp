#include <iostream>

using namespace std;

class R
{
    public:
        R(int r1, int r2) {
            R1 = r1;
            R2 = r2;
        }
        void print();
        void print() const;     // const可以区分成员重载函数

    private:
        int R1, R2;
};
/*
通常常对象只能调用它的常成员函数
*/

void R::print()
{
    cout << "普通调用" << endl;
    cout << R1 << ":" << R2 << endl;
}

// 实现时需要带const关键字
void R::print() const
{
    cout << "常对象调用" << endl;
    cout << R1 << ";" << R2 << endl;
}

int main(int argc, char const *argv[])
{
    R a(5, 4);
    a.print();

    // 常对象调用常成员函数
    const R b(20, 52);
    b.print();

    system("read -p 'Press Enter to continue...' var");
    return 0;
}
