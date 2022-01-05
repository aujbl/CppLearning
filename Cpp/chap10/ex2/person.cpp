#include "person.h"
#include <cstring>
#include <iostream>

Person::Person(const std::string &ln, const char * fn)
{
    lname = ln;
    std::strcpy(fname, fn);
}

void Person::show() const
{
    std::cout << "first name: " << fname << "\tlast name: " << lname << std::endl;
}

void Person::FormalShow() const
{
    std::cout << "last name: " << lname << "\tfirst name: " << fname << std::endl;
}