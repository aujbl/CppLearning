#include<iostream>
using namespace std;
class MyClass
{
public:
    MyClass(int i = 0)
    {
        cout << i;
    }
    MyClass(const MyClass &x)
    {
        cout << 2;
    }
    MyClass &operator=(const MyClass &x)
    {
        cout << 3;
        return *this;
    }
    ~MyClass()
    {
        cout << 4;
    }
};
int main()
{
    MyClass obj1(1), obj2(2);       //output: 1, 2
    // MyClass obj3 = obj1;     // 等价于 MyClass obj3(obj1);  122444

    MyClass obj3;               //output: 1
    obj3 = obj1;                //MyClass &operator=(const MyClass x) 形参无引用时，先调用2复制新对象，然后赋给3
                                //有引用时，将1赋给3

    return 0;
}