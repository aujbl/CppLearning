#include <iostream>
#include <cstring>

using namespace std;
int Fill_array(double arr[], int size);
void Show_array(double arr[], int size);
void Reverse_array(double arr[], int size);

int main()
{
    int size = 10;
    double p[size];
    int input_num = Fill_array(p, size);
    cout << "total input nums = " << input_num << endl;
    Show_array(p, input_num);
    Reverse_array(p, input_num);
    cout << "show reverse array.\n";
    Show_array(p, input_num);
    Reverse_array(p+1, input_num-2);
    cout << "show reverse-1 array.\n";
    Show_array(p, input_num);
    return 0;
}

int Fill_array(double arr[], int size)
{
    cout << "enter double nums.\n";
    int cnt = 0;
    while ((cnt < size) && (cin >> arr[cnt]))
    {   
        cout << "num " << cnt+1 << " = " << arr[cnt] << endl;
        ++cnt;
    }
    return cnt;
}

void Show_array(double arr[], int size)
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << "\t";
    cout << endl;
}

void Reverse_array(double arr[], int size)
{
    int i, j;
    double tmp;
    for (i = 0, j = size - 1; i < j; ++i, --j)
    {
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}