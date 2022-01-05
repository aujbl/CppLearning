#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
    string ch;
    cout << "enter words.\n";
    int c_num, v_num, other;
    c_num = v_num = other = 0;
    while ((cin >> ch) and (ch != "q"))
    {
        if (isalpha(ch[0]))
        {
            switch (ch[0])
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    v_num += 1;
                    break;
                default:
                    c_num += 1;
            }
        }
        else
            other += 1;
    }
    cout << v_num << " words beginning with vowels.\n";
    cout << c_num << " words beginning with consonants.\n";
    cout << other << " others.\n";

    return 0;
}
