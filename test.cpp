#include <iostream>
using namespace std;

int main(){
    int a[10] = {0, 1,2,3,4,5,6,7,8,9};
    int (*p)[10] = &a;
    int *p1 = (int *)p;
    cout << *p1 << endl;

    return 0;
}
