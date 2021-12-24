#include <iostream>
#include <cstring>

using namespace std;
const int Arsize = 8;

int sum_arr(const int arr[], int n);
int sum(int arr[][4], int size);
int sum(int (*arr)[4], int size);

int main()
{
/*   --------------------1--------------------------
    int cookies[Arsize] = {1, 2, 4, 8, 16, 32, 64, 128};
    cout << "cookies = " << cookies << endl;
    cout << "sizeof cookies = " << sizeof cookies << endl;
    int sum = sum_arr(cookies, Arsize);
    cout << "total sum = " << sum << endl;
    sum = sum_arr(cookies, 3);
    cout << "first three sum = " << sum << endl;
    sum = sum_arr(cookies + 4, 4);
    cout << "last four sum = " << sum << endl;
*/
    // const int **pp2;
    // int * p1;
    // const int n = 13;
    // pp2 = &p1;
    // *pp2 = &n;
    // *p1 = 10;     //指针错误例子

    int data[3][4] = {{1, 2, 3, 4}, {9, 8, 7, 6}, {2, 4, 6, 8}};
    cout << "sum(data, 3) = " << sum(data, 3) << endl;


    return 0;
}

// int sum(int arr[][4], int size)
int sum(int (*arr)[4], int size)
{
    int total = 0;
    for (int r = 0; r < size; ++r)
    {
        for (int c = 0; c < 4; ++c)
            total += arr[r][c];
    }
    return total;
}


/*  ------------------------1----------------------
int sum_arr(const int* arr, int n)
{
    int total = 0;
    cout << "arr = " << arr << endl;
    cout << "sizeof arr = " << sizeof arr << endl;
    for (int i = 0; i < n; ++i)
        total += arr[i];
    return total;
}
*/
