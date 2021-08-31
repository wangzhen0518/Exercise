#ifndef LIST_H_
#define LIST_H_

typedef int Item;

class List
{
private:
    static const int Len = 10;
    int used;
    Item arr[Len];

public:
    List(const Item a[] = {0}, int len = 0);
    ~List();
    bool isfull() const;
    bool isempty() const;
    bool push(const Item &t);
    void visit(void (*pf)(Item &));
};

#endif