#include <iostream>

using namespace std;

/*
尽管使用了前向引用声明，但是在提供一个完整的类声明之前，不能声明该类的对象
*/

// 第一种
class Fred;     // 前向引用声明
class Barney
{
    Fred x;     // 错误：类Fred的声明尚不完善
};
class Fred
{
    Barney y;
};


// 第二种
class Fred;     // 前向引用声明
class Barney
{
    public:
        void method()
        {
            x->yabbaDabbaDo();      // 错误：Fred类的对象在定义前被使用
        }
    private:
        Fred *x;        // 前向引用后可以声明Fred类的对象指针
};

class Fred
{
    public:
        void yabbaDabbaDo();
    private:
        Barney *y;
};

/*
当使用前向引用声明时，只能使用被声明的符号，不能涉及类的细节
*/