#include <iostream>

using namespace std;
void move(char, char);
void hanoi(int, char, char, char);

int main(int argc, char const *argv[])
{
    cout << "Enter nums of disks: ";
    int disks;
    cin >> disks;
    hanoi(disks, 'A', 'B', 'C');

    system("read -p 'Press Enter to continue...' var");
    return 0;
}


void move(char A, char B)
{
    cout << A << " -> " << B << endl;
}

void hanoi(int n, char A, char B, char C)
{
    if (n == 1)
        move(A, C);
    else
    {
        hanoi(n - 1, A, C, B);  // A -> B
        move(A, C);             // A -> C
        hanoi(n - 1, B, A, C);  // B -> C
    }
}
