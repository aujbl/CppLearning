#include "golf.h"
#include <cstring>
#include <iostream>
using namespace std;

void setgolf(golf &g, const char *name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf &g)
{
    char name[Len];
    cout << "please enter g's fullname.\n";
    cin.getline(name, Len);
    if (!strcmp(name, ""))
        return 0;
    strcpy(g.fullname, name);
    return 1;
}

void handicap(golf &g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf &g)
{
    cout << "fullname: " << g.fullname << endl;
    cout << "handicap: " << g.handicap << endl;
}