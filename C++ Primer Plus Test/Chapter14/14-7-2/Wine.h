#ifndef WINE_H_
#define WINE_H_

#include <iostream>
#include <valarray>

template <class T1, class T2>
class Pair
{
private:
    T1 a;
    T2 b;

public:
    T1 &first();
    T2 &second();
    T1 first() const { return a; }
    T2 second() const { return b; }
    Pair(const T1 &aval, const T2 &bval) : a(aval), b(bval) {}
    Pair() {}
};

template <class T1, class T2>
T1 &Pair<T1, T2>::first()
{
    return a;
}
template <class T1, class T2>
T2 &Pair<T1, T2>::second()
{
    return b;
}

using ArrayInt = std::valarray<int>;
using PairArray = Pair<ArrayInt, ArrayInt>;
class Wine : private PairArray
{
private:
    std::string name;

public:
    Wine() {}
    Wine(const char *l, int y, const int yr[], const int bot[])
        : name(l), PairArray(std::valarray<int>(yr, y), std::valarray<int>(bot, y)) {} //是否会有问题？
    Wine(const char *l, int y)
        : name(l), PairArray(std::valarray<int>(y), std::valarray<int>(y)) {}
    ~Wine() {}
    void GetBottles();
    std::string &Label();
    int sum();
    void Show() const;
};

inline void Wine::GetBottles()
{
    using std::cin;
    using std::cout;
    using std::endl;

    int y = PairArray::first().size();
    cout << "Enter " << name << " data for " << y << " year(s):\n";
    for (int i = 0; i < y; i++)
    {
        cout << "Enter year: ";
        cin >> PairArray::first()[i];
        cout << "Enter bottles for that year: ";
        cin >> PairArray::second()[i];
    }
    cout << endl;
}

inline std::string &Wine::Label()
{
    return name;
}

inline int Wine::sum()
{
    return PairArray::second().sum();
}

inline void Wine::Show() const
{
    using std::cout;
    using std::endl;

    cout << "Wine: " << name << endl;
    cout << "\tYear\tBottles\n";

    int y = PairArray::first().size();
    for (int i = 0; i < y; i++)
    {
        cout << "\t" << PairArray::first()[i]
             << "\t" << PairArray::second()[i] << endl;
    }
}

#endif