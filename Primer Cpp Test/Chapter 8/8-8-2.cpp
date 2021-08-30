#include <iostream>

struct CandyBar
{
    std::string TypeName;
    double weight;
    int heat;
};

void set(CandyBar &cb, std::string name = "Millennium Munch", double w = 2.85, int h = 350)
{
    cb.TypeName = name;
    cb.weight = w;
    cb.heat = h;
}

void show(const CandyBar &cb)
{
    using std::cout, std::endl;
    cout << "Name: " << cb.TypeName << endl;
    cout << "Weight: " << cb.weight << endl;
    cout << "Heat: " << cb.heat << endl;
}

int main()
{
    CandyBar cb;
    set(cb);
    show(cb);
    return 0;
}