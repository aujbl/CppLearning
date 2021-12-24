#include "person.h"
#include <iostream>
#include <cstring>

int main()
{
    Person one;
    Person two("Smyth");
    Person three("Dim", "Sam");

    one.show();
    // std::cout << std::endl;
    one.FormalShow();

    two.show();
    // std::cout << std::endl;
    two.FormalShow();

    three.show();
    // std::cout << std::endl;
    three.FormalShow();
}