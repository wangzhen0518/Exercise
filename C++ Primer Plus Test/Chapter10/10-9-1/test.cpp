#include"BankAccount.h"
#include<iostream>

int main()
{
    BankAccount t("wangzhen", "PB19000078", 10.0);
    t.show();
    t.save(20.0);
    t.withdraw(23.5);
    t.show();
    return 0;
}