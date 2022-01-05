#include <iostream>
#include <cstring>
using namespace std;

struct free_throws
{
    string name;
    int made;
    int attempts;
    float percent;
};

free_throws &accumulate(free_throws &target, const free_throws &source);
void display(const free_throws &ft);

int main()
{
    free_throws one = {"one", 1, 11};
    free_throws two = {"two", 2, 22};
    free_throws four = {"four", 4, 44};
    free_throws team = {"team", 0, 0};

    free_throws dup;
    dup = accumulate(team, one);
    accumulate(dup, two) = four;
    display(dup);
    display(team);

    return 0;
}


free_throws & accumulate(free_throws &target, const free_throws &source)
{
    target.attempts += source.attempts;
    target.made += source.made;
    return target;
}

void display(const free_throws &ft)
{
    cout << "name: " << ft.name << endl;
    cout << "made = " << ft.made << '\t';
    cout << "attempt = " << ft.attempts << '\t';
    cout << "percent = " << ft.percent << endl;
}