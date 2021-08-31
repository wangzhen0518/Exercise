#include <iostream>
#include "List.h"

List::List(const Item a[], int len)
{
    if (len < 4)
        used = len;
    else
        used = 4;
    for (int i = 0; i < len; i++)
        arr[i] = a[i];
    for (int i = used; i < Len; i++)
        arr[i] = 0;
}
List::~List() {}

bool List::isfull() const
{
    if (used == Len)
        return true;
    else
        return false;
}

bool List::isempty() const
{
    if (used == 0)
        return true;
    else
        return false;
}

bool List::push(const Item &t)
{
    if (used == Len)
        return false;
    else
    {
        arr[used] = t;
        return true;
    }
}

void List::visit(void(*pf)(Item&))
{
    for (int i = 0; i < used;i++)
        pf(arr[i]);
}