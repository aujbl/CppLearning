#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    struct donator
    {
        string name = "";
        double patrons = 0;
    };
    
    
    int donators_num;
    cout << "Please enter donators num.\n";
    cin >> donators_num;
    cin.get();     //丢弃回车
    donator *dona = new donator[donators_num];
    for (int i = 0; i < donators_num; ++i)
    {
        cout << "donator " << i+1 << endl;
        cout << "donator's name\n";
        getline(cin, dona[i].name); //读取行，名字可能包含空格
        cout << "patrons\n";
        cin >> dona[i].patrons;
        cin.get();      //丢弃空格
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

        return 0;
}
