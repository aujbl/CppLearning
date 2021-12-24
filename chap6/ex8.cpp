#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("test.txt");
    if (!inFile.is_open())
    {
        cout << "open wrong file.\n";
        exit(EXIT_FAILURE);
    }

    char ch;
    int nums = 0;
    while ((inFile.get(ch)))
        nums += 1;
    cout << "There are " << nums << " chars totally.\n";

    return 0;
}
