#include <iostream>
#include "Plorg.h"

int main()
{
    plorg t("wangzhen", 10);
    plorg t2;
    t.show();
    t2.show();
    t.setCI(20);
    t.show();
    return 0;
}