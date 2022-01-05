#include <iostream>
#include <string>
#include "account.h"

int main()
{
    Account a{"a", 1, 0};
    a.deposit(100);
    a.deposit(-1);
    a.take(10);
    a.take(100);
    a.show();
}