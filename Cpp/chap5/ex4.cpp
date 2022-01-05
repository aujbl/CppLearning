#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    double d_asset, c_asset;
    d_asset = c_asset = 100;
    while (d_asset >= c_asset)
    {
        d_asset += 10;
        c_asset += (0.05 * c_asset);
    }
    cout << "d_asset = " << d_asset << "  c_asset = " << c_asset << endl;

    return 0;
}
