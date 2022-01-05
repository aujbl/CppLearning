#include "golf.h"
#include <iostream>
#include <cstring>


int main()
{
    Golf g("ggg");
    g.showgolf();

    g.setgolf();
    g.showgolf();

    g.handicap(100);
    g.showgolf();

}