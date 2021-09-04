#ifndef CD_H_
#define CD_H_
class Cd
{
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;

public:
    Cd(const char *s1, const char *s2, int n, double x);
    Cd(const Cd &d);
    Cd();
    virtual ~Cd(){};
    virtual void Report() const;
    Cd &operator=(const Cd &d);
};

class Classic : public Cd
{
private:
    char main_works[100];

public:
    Classic(const char *s1, const char *s2, const char *s3, int n, double x);
    Classic();
    virtual ~Classic() {}
    virtual void Report() const;
    Classic &operator=(const Classic &d);
};
#endif
