#ifndef _PERSON_
#define _PERSON_
#include <string>
class Person
{
private:
    static const int LIMIT = 25;
    std::string lname;
    char fname[LIMIT];

public:
    Person()
    {
        lname = "";
        fname[0] = '\0';
    }
    Person(const std::string &ln, const char *fn = "Heyyou");
    ~Person();
    void Show() const;
    void FormalShow() const;
};
#endif