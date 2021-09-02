#include<iostream>
#include"Cow.h"

int main()
{
    Cow c;
    c.ShowCow();
    c = {"cyl", "watch movie", 100};
    c.ShowCow();
    return 0;
}