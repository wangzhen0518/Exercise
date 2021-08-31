#include <iostream>
#include "Move.h"

int main()
{
    Move t1(3.3, 4.3);
    Move t2(2.3, 1.2);
    t1.showmove();
    t2.showmove();
    Move tx = t1.add(t2);
    tx.showmove();
    tx.reset(2.1, 5.4);
    tx.showmove();
    return 0;
}