#include <iostream>
#include "Person.h"

int main()
{
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");
    three.Show();
    three.FormalShow();

    return 0;
}