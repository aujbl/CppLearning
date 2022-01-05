#include "account.h"
#include <iostream>
#include <string>

Account::Account(std::string name, long account_num, double account)
{
    m_name = name;
    m_account_num = account_num;
    m_account = account;
}

void Account::deposit(double num)
{
    if (num < 0)
        std::cout << "wrong num.\n"; 
    else
    {
        m_account += num;
        std::cout << "deposit: " << num << " success. balance: " << m_account << std::endl;
    }
}

void Account::take(double num)
{
    if (num < 0)
        std::cout << "wrong num.\n";
    else
    {
        if (num > m_account)
            std::cout << "no enough money in your account.\n";
        else
        {
            m_account -= num;
            std::cout << "take " << num << " . balance: "<< m_account << std::endl;
        }
    }
}

void Account::show()
{
    std::cout << "account name: " << m_name << std::endl;
    std::cout << "account num: " << m_account_num << std::endl;
    std::cout << "account balance: " << m_account << std::endl;
}
