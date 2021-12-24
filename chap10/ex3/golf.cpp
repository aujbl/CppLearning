#include "golf.h"
#include <cstring>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

Golf::Golf(const char *name, int hc)
{
    std::strcpy(fullname, name);
    m_handicap = hc;
}

void Golf::setgolf()
{
    char name[Len];
    cout << "please enter g's fullname.\n";
    cin.getline(name, Len);
    if (!strcmp(name, ""))
        cout << "no enter.\n" << endl;
    else
        *this = Golf(name);
}

void Golf::handicap(int hc)
{
    m_handicap = hc;
}

void Golf::showgolf() const 
{
    cout << "golf player's fullname: " << fullname << endl;
    cout << "handicap: " << m_handicap << endl;
}