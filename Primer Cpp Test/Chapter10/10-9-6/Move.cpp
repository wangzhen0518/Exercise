#include "Move.h"
#include <iostream>

Move::Move(double a, double b)
{
    x = a;
    y = b;
    //std::cout << "over\n";
}
Move::~Move() {}

void Move::showmove() const
{
    using std::cout;
    using std::endl;
    cout << "x: " << x << ", y: " << y << endl;
}

Move Move::add(const Move &m) const
{
    //std::cout << "out add\n";
    return Move(this->x + m.x, this->y + m.y);
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}