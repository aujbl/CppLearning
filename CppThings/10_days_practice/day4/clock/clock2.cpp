#include <iostream>
/*
设计一个时钟类，能够记录时、分、秒，
重载它的++运算符，每执行一次++运算，加时1秒，但要使计时过程能够自动进位。
*/
using namespace std;
class Time{
    public:
        Time(int h=0, int m=0, int s=0){
            hour = h;
            minute = m;
            second = s;
        }
        void operator++();
        void showTime(){
            cout << "time: " << hour << ":" << minute << ":" << second << endl;
        }

    private:
        int hour, minute, second;
};

void Time::operator++()
{
    ++second;
    if(second==60){
        second = 0;
        ++minute;
        if(minute==60){
            minute = 0;
            ++hour;
            hour %= 24;
        }
    }
}

int main(int argc, char const *argv[])
{
    Time t(23, 59, 59);
    ++t;
    t.showTime();

    system("read -p 'Press Enter to continue...' var");
    return 0;
}
