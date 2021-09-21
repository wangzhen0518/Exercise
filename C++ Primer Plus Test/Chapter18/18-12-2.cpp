#include <iostream>

class Cpmv
{
public:
    struct Info
    {
        std::string qcode;
        std::string zcode;
    };

private:
    Info *pi;

public:
    Cpmv() : pi(nullptr) { std::cout << "default\n"; }
    Cpmv(const std::string &q, const std::string &z)
    {
        std::cout << "string q, string z\n";
        pi = new Info;
        pi->qcode = q;
        pi->zcode = z;
    }
    Cpmv(const Cpmv &cp)
    {
        std::cout << "const Cpmv&\n";
        pi = new Info;
        pi->qcode = cp.pi->qcode;
        pi->zcode = cp.pi->zcode;
    }
    Cpmv(Cpmv &&mv)
    {
        std::cout << "Cpmv&&\n";
        pi = mv.pi;
        mv.pi = nullptr;
    }
    ~Cpmv()
    {
        std::cout << "delete\n";
        delete pi;
    }
    Cpmv &operator=(const Cpmv &cp)
    {
        std::cout << "operator=&\n";
        if (this != &cp)
        {
            delete pi;
            pi = new Info;
            pi->qcode = cp.pi->qcode;
            pi->zcode = cp.pi->zcode;
        }
        return *this;
    }
    Cpmv &operator=(Cpmv &&mv)
    {
        std::cout << "operator=&&\n";
        if (this != &mv)
        {
            pi = mv.pi;
            mv.pi = nullptr;
        }
        return *this;
    }
    Cpmv operator+(const Cpmv &obj) const
    {
        std::cout << "operator+\n";
        return Cpmv(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode);
    }
    void Display() const
    {
        if (pi == nullptr)
            std::cout << "pi is nullptr\n";
        else
            std::cout << "qcode: " << pi->qcode << ", zcode: " << pi->zcode << std::endl;
    }
};

int main()
{
    using namespace std;
    Cpmv cp1("C ", "++ ");
    cp1.Display();
    Cpmv cp2("Computer ", "Science ");
    cp2.Display();
    Cpmv cp3 = cp2;
    cp3.Display();
    cp2 = cp1;
    cp2.Display();
    cp1 = cp2 + cp3;
    cp1.Display();
    Cpmv cp4(cp1 + cp3);
    cp4.Display();

    return 0;
}