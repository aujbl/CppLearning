#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
const int SLEN = 30;
struct student{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};
int getinfo(student pa[], int n);
void display1(student st);
void display2(const student *ps);
void display3(const student pa[], int n);

int main()
{
    student pa[5];
    int num_stu = getinfo(pa, 5);
    cout << "num of student = " << num_stu << endl;
    cout << "---------------display1:----------------------\n";
    for (int i = 0; i < num_stu; ++i)
        display1(pa[i]);   
    cout << "---------------display2:----------------------\n";
    for (int i = 0; i < num_stu; ++i)
        display2(pa+i);
    cout << "---------------display3:----------------------\n";
    display3(pa, num_stu);

    return 0;
}

int getinfo(student pa[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        cout << "enter student's fullname.\n";
        cin.getline(pa[i].fullname, SLEN);
        if (strspn(pa[i].fullname, " \t\n") == strlen(pa[i].fullname))
        {
            cout << "black line, end.\n";
            break;
        }
        else 
        {
            cout << "hobby: \n";
            cin.getline(pa[i].hobby, SLEN);
            cout << "ooplevel: \n";
            cin >> pa[i].ooplevel;
            cin.get();
        }
    }
    return i;
}

void display1(student st)
{
    cout << "st.fullname: " << st.fullname << endl;
    cout << "st.hobby: " << st.hobby << endl;
    cout << "st.ooplevel: " << st.ooplevel << endl;
}


void display2(const student *ps)
{
    cout << "ps->fullname: " << ps->fullname << endl;
    cout << "ps->hobby: " << ps->hobby << endl;
    cout << "ps->ooplevel: " << ps->ooplevel << endl;
}


void display3(const student pa[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << "fullname: " << pa[i].fullname << endl;
        cout << "hobby: " << pa[i].hobby << endl;
        cout << "ooplevel: " << pa[i].ooplevel << endl;
    }
}


