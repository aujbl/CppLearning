#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const int SIZE = 10;
    double donation[10];
    int nums = 0;
    double dona = 0., total = 0.;
    while ((nums < SIZE) and (cin >> dona))
    {
        donation[nums] = dona;
        total += dona;
        nums += 1;
    }
    double avg = 0.;
    if (nums == 0)
        cout << "there is no num. avg = " << avg << endl;
    else if (nums < 2)
    {   
        avg = total / nums;
        cout << "there is " << nums << " num. avg = " << avg << endl;   
    }
    else
    {
        avg = total / nums;
        cout << "there are " << nums << " nums. avg = " << avg << endl;
    }
        
    int cnt = 0;
    for (int i = 0; i < nums; ++i)
        if (donation[i] > avg)
            cnt += 1;
    if (cnt < 2)
        cout << cnt << " num";        
    else
        cout << cnt << " nums";
    cout << " bigger than avg.\n";
    return 0;
}
