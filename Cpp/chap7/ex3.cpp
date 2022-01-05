#include <iostream>
#include <cstring>

using namespace std;
void show_box(struct box b);
void cal_volumn(struct box *p);
void show(struct box b);

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volumn;
};

int main()
{
    box b = {"aaa aaa", 1., 2., 3., 4.};
    show(b);

    return 0;
}

void show_box(struct box b)
{
    cout << "b.maker: " << b.maker << endl;
    cout << "b.height: " << b.height << endl;
    cout << "b.width: " << b.width << endl;
    cout << "b.length: " << b.length << endl;
    cout << "b.volumn: " << b.volumn << endl;
}

void cal_volumn(struct box *p)
{
    p->volumn = p->height * p->length * p->width;
}

void show(struct box b)
{
    show_box(b);
    cal_volumn(&b);
    show_box(b);
}