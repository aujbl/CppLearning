#ifndef CLOCK
# define CLOCK
class Clock
{
    public:
        Clock(int NewH, int NewM, int NewS);
        Clock(Clock &c);
        void SetTime(int NewH, int NewM, int NewS);
        void ShowTime();
        ~Clock();

    private:
        int Hour, Minute, Second;
};

#endif