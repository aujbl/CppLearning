#include <iostream>
#include <cstring>

struct stringy
{
    char *str;
    int ct;
};

using namespace std;
void show(const char *t, unsigned int cnt=1);
void show(const stringy &b, unsigned int cnt = 1);
void set(stringy &b, char *test);



int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to ve.";

    set(beany, testing);
    show(beany);
    show(beany, 3);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);

    delete beany.str;

    return 0;
}


void set(stringy &b, char* test)
{
    b.str = new char [strlen(test) + 1];
    strcpy(b.str, test);
}

void show(const char * t, unsigned int cnt)
{
    for (unsigned int i = 0; i < cnt; ++i)
        cout << t << endl;
}

void show(const stringy &b, unsigned int cnt)
{
    for (unsigned int i = 0; i < cnt;++i)
        cout << b.str << endl;
}





