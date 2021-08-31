#ifndef BANKACCOUT
#define BANKACCOUT
#include <string>
class BankAccount
{
private:
    std::string m_name;
    std::string m_id;
    double m_saving;

public:
    BankAccount(std::string name = "None",
                std::string id = "None", double saving = 0.0);
    ~BankAccount();
    void show();
    bool save(double num);
    bool withdraw(double num);
};
#endif