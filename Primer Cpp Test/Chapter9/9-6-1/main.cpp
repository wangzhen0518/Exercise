#include <iostream>
#include "golf.cpp"

int main()
{
    golf g;
    setgolf(g);
    showgolf(g);
    handicap(g, 10);
    showgolf(g);
    return 0;
}