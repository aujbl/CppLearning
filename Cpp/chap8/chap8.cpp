#include <iostream>
#include <cstring>
struct free_throws
{
    std::string name;
    int made;
};


free_throws & accumulate(free_throws & target, const free_throws & source);
void display(const struct free_throws & ft);
const free_throws &clone(free_throws &ft);
const free_throws &clone1(free_throws &ft);
using namespace std;




int main()
{
    /* //---------------1--------------------------
    int rats = 101;
    int *pt = &rats;
    int &rodents = *pt;
    int bunnies = 50;
    pt = &bunnies;
    cout << "*pt = " << *pt << endl;
    cout << "rodents = " << rodents << endl;
    rodents = bunnies;
    cout << "rodents = " << rodents <<" address of rodents = " << &rodents << endl;
    cout << "rats = " << rats << " address of rats = " << &rats << endl;
    cout << "bunnies = " << bunnies << " address of bunnies = " << &bunnies << endl;
    */
    //----------------------2----------------

    free_throws four = {"four", 4};
    free_throws five = {"five", 5};
    free_throws dup;
    // display(five);
    // display(dup);
    // free_throws &five1 = accumulate(five, four);
    // cout << "address of five: " << &five << endl;
    // cout << "addres of five1: " << &five1 << endl;
    // five1 = four;
    // display(five);
    // display(five1);
    cout << "...\n";
    free_throws clone_1 = clone(five);
    // free_throws clone_2 = clone1(five);
    // display(five);
    // display(clone_1);
    display(clone_1);
    cout << "address of clone_1: " << &clone_1 << endl;

    return 0;
}


struct free_throws & accumulate(free_throws & target, const free_throws & source)
{
    target.name += source.name;
    target.made += source.made;
    return target;
}

void display(const struct free_throws & ft)
{
    std::cout << "name = " << ft.name << std::endl;
    std::cout << "made = " << ft.made << std::endl;
}

const free_throws & clone(free_throws & ft)
{
    free_throws *pt;
    *pt = ft;
    // cout << "addredd of pt: " << pt << endl;
    // cout << "address of ft: " << &ft << endl;
    return *pt;
}

// const free_throws & clone1(free_throws & ft)
// {
//     free_throws newguy;
//     newguy = ft;
//     cout << "address of newguy: " << &newguy << endl;
//     cout << "addredd of ft: " << &ft << endl;
//     return newguy;
// }