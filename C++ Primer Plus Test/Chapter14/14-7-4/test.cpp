#include <iostream>
#include "Person.h"

int main()
{
    BadDude t;
    t.Show();
    std::cout << "Gdraw: " << t.Gdraw()
              << ", Cdraw: " << t.Cdraw()
              << std::endl;
    return 0;
}