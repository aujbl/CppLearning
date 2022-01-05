#ifndef GOLF_H_
#define GOLF_H_

class Golf
{
private:
    static const int Len = 40;
    char fullname[Len];
    int m_handicap;
public:
    Golf(const char *name, int hc=0);
    void setgolf();
    void handicap(int hc);
    void showgolf() const;
};

#endif