#ifndef PLORG_H_
#define PLORG_H_
class plorg
{
private:
    static const int Len = 20;
    char m_name[Len];
    int m_CI;

public:
    plorg(const char name[] = "Plorga", int CI = 50);
    ~plorg();
    void setCI(int CI);
    void show() const;
};
#endif