#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <string>

class abstr_emp
{
private:
    std::string fname;
    std::string lname;
    std::string job;

public:
    abstr_emp() : fname("no"), lname("body"), job("none") {}
    abstr_emp(const std::string &fn, const std::string &ln,
              const std::string &j)
        : fname(fn), lname(ln), job(j) {}
    virtual void ShowAll() const
    {
        std::cout << "name: " << fname << " " << lname
                  << "\njob: " << job << std::endl;
    }
    virtual void SetAll()
    {
        using std::cin;
        using std::cout;
        using std::endl;

        cout << "Enter first name: ";
        cin >> fname;
        cout << "Enter last name: ";
        cin >> lname;
        cout << "Enter job: ";
        cin >> job;
    }
    friend std::ostream &operator<<(std::ostream &os, const abstr_emp &e)
    {
        os << e.fname << " " << e.lname << ", " << e.job;
        return os;
    }
    ~abstr_emp() {}
};

class employee : public abstr_emp
{
public:
    employee() : abstr_emp() {}
    employee(const std::string &fn, const std::string &ln,
             const std::string &j)
        : abstr_emp(fn, ln, j) {}
    ~employee() {}
    virtual void ShowAll() const { abstr_emp::ShowAll(); }
    virtual void SetAll() { abstr_emp::SetAll(); }
};

class manager : virtual public abstr_emp
{
private:
    int inchargeof;

protected:
    int InChargeOf() const { return inchargeof; }
    int &InChargeOf() { return inchargeof; }

public:
    manager() : abstr_emp(), inchargeof(0) {}
    manager(const std::string &fn, const std::string &ln,
            const std::string &j, int ico = 0)
        : abstr_emp(fn, ln, j), inchargeof(ico) {}
    manager(const abstr_emp &e, int ico)
        : abstr_emp(e), inchargeof(ico) {}
    manager(const manager &m)
        : abstr_emp(m), inchargeof(m.inchargeof) {}
    ~manager() {}
    virtual void ShowAll() const
    {
        abstr_emp::ShowAll();
        std::cout << "in charge of: " << inchargeof << std::endl;
    }
    virtual void SetAll()
    {
        abstr_emp::SetAll();
        std::cout << "Enter inchargeof: ";
        std::cin >> inchargeof;
    }
};

class fink : virtual public abstr_emp
{
private:
    std::string reportsto;

protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string &ReportsTo() { return reportsto; }

public:
    fink() : abstr_emp(), reportsto("none") {}
    fink(const std::string &fn, const std::string &ln,
         const std::string &j, const std::string &rpo)
        : abstr_emp(fn, ln, j), reportsto(rpo) {}
    fink(const abstr_emp &e, const std::string &rpo)
        : abstr_emp(e), reportsto(rpo) {}
    fink(const fink &e)
        : abstr_emp(e), reportsto(e.reportsto) {}
    ~fink() {}
    virtual void ShowAll() const
    {
        abstr_emp::ShowAll();
        std::cout << "reportsto: " << reportsto << std::endl;
    }
    virtual void SetAll()
    {
        abstr_emp::SetAll();
        std::cout << "Enter reportsto: ";
        std::cin >> reportsto;
    }
};

class highfink : public manager, public fink
{
public:
    highfink() : manager(), fink(), abstr_emp() {}
    highfink(const std::string &fn, const std::string &ln,
             const std::string &j, const std::string &rpo,
             int ico)
        : abstr_emp(fn, ln, j), fink(fn, ln, j, rpo), manager(fn, ln, j, ico) {}
    highfink(const abstr_emp &e, const std::string &rpo, int ico)
        : abstr_emp(e), fink(e, rpo), manager(e, ico) {}
    highfink(const fink &f, int ico)
        : abstr_emp(f), fink(f), manager(f, ico) {}
    highfink(const manager &m, const std::string &rpo)
        : abstr_emp(m), fink(m, rpo), manager(m) {}
    highfink(const highfink &h)
        : abstr_emp(h), fink(h), manager(h) {}
    ~highfink() {}
    virtual void ShowAll() const
    {
        abstr_emp::ShowAll();
        std::cout << "reportsto: " << fink::ReportsTo() << std::endl;
        std::cout << "in charge of: " << manager::InChargeOf() << std::endl;
    }
    virtual void SetAll()
    {
        abstr_emp::SetAll();
        std::cout << "Enter reportsto: ";
        std::cin >> fink::ReportsTo();
        std::cout << "Enter in charge of: ";
        std::cin >> manager::InChargeOf();
    }
};

#endif