#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    struct donator
    {
        string name = "";
        double patrons = 0;
    };

    ifstream inFile;
    inFile.open("dona.txt");
    if (!inFile.is_open())
        exit(EXIT_FAILURE);

    string ch;
    int donators_num;
    inFile >> donators_num;
    inFile.get();
    donator *dona = new donator[donators_num];
    for (int i = 0; i < donators_num; ++i)
    {
        getline(inFile, dona[i].name); //读取行，名字可能包含空格
        inFile >> dona[i].patrons;
        inFile.get();      //丢弃空格
    }

    cout << "------Grand Patrons------\n";
    for (int i = 0; i < donators_num; ++i)
    {
        if (dona[i].patrons > 10000)
            cout << dona[i].name <<"\t\t" << dona[i].patrons << endl;
    }

    cout << "------Patrons------\n";
    for (int i = 0; i < donators_num; ++i)
    {
        if (dona[i].patrons <= 10000)
            cout << dona[i].name << "\t\t" << dona[i].patrons << endl;
    }

    inFile.close();
    delete[] dona;
    return 0;
}
