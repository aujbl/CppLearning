#include <iostream>
#include <cstring>

using namespace std;
void upper(string &s);

int main()
{
    cout << "enter a string or (q to quit)" << endl;
    string s;
    while ((getline(cin, s)) && (s != "q"))
    {
        upper(s);
        cout << s << endl;
    }

    return 0;
}

void upper(string & s)
{
    for (unsigned int i = 0; i < s.length(); ++i)
    {
        if (islower(s[i]))
        {
            s[i] = toupper(s[i]);
        }
    }
}