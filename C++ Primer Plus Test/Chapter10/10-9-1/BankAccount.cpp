#include <iostream>
#include "BankAccount.h"

BankAccount::BankAccount(std::string name, std::string id, double saving)
{
    m_name = name;
    m_id = id;
    m_saving = saving;
}
BankAccount::~BankAccount() {}

void BankAccount::show()
{
    using std::cout;
    using std::endl;
    cout << "Account owner's name: " << m_name << endl;
    cout << "Account id: " << m_id << endl;
    cout << "Account saving: " << m_saving << endl;
}

bool BankAccount::save(double num)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Input shouldn't less than 0\n";
        return false;
    }
    else
    {
        m_saving += num;
        return true;
    }
}
bool BankAccount::withdraw(double num)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Input shouldn't less than 0\n";
        return false;
    }
    else
    {
        m_saving -= num;
        return true;
    }
}