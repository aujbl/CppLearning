#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <string>

class Account
{
    private:
        std::string m_name;
        long m_account_num;
        double m_account;
    public:
        Account(std::string name, long account_num, double account);
        void deposit(double num);
        void take(double num);
        void show();
};

#endif