#include <iostream>

using namespace std;

struct student
{    
    char gender;
    char black;
    int num;
    char name[20];
  
};

int main(int argc, char const *argv[])
{
    student s = {'M', ' ', 10, "asd"};
    cout << s.num << endl;
    cout << sizeof(s.num) << endl;
    cout << sizeof(s.name) << endl;
    cout << sizeof(s.gender) << endl;
    cout << sizeof(s.black) << endl;
    cout << sizeof(s) << endl;

    system("read -p 'Press Enter to continue...' var");
    return 0;
}
