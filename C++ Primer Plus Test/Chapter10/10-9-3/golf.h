#ifndef _GOLF_
#define _GOLF_
class golf
{
private:
    static const int Len = 40;
    char m_fullname[Len];
    int m_handicap;

public:
    golf(const char *name = "None", int hc = 0);
    ~golf();
    bool setgolf();
    void handicap(int hc);
    void show() const;
};
#endif
