#include <iostream>

using namespace std;

class Point{
    protected:
        int x, y;
    public:
        Point(int a, int b=0){
            x = a;
            y = b;
            cout << "constructing point(" << x << ", " << y << ")" << endl;
        }
};

class Line:public Point{
    protected:
        int len;
    public:
        // 构造函数初始化列表，将参数传递给基类
        Line(int a, int b, int l):Point(a, b){
            len = l;
            cout << "Constructing Line, len..." << len << endl;
        }
};

int
main(int argc, char const *argv[])
{
    Line L1(1, 2, 3);

    system("read -p 'Press Enter to continue...' var");
    return 0;
}
