#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <iostream>
#include <cstdlib>

class Person
{
private:
    std::string m_fname;
    std::string m_lname;

public:
    Person(const std::string fname = "no", const std::string lname = "body")
        : m_fname(fname), m_lname(lname) {}
    virtual ~Person() {}
    virtual void Show() const { std::cout << m_fname << " " << m_lname << std::endl; }
};

class Gunslinger : virtual public Person
{
private:
    double m_time;
    int m_num;

public:
    Gunslinger(const std::string fname = "no", const std::string lname = "body",
               double time = 0.0, int num = 0)
        : Person(fname, lname), m_time(time), m_num(num) {}
    virtual ~Gunslinger() {}
    double Draw() const { return m_time; }
    virtual void Show() const
    {
        Person::Show();
        std::cout << "time: " << m_time << ", number: " << m_num << std::endl;
    }
};

class PokerPlayer : virtual public Person
{
public:
    PokerPlayer(const std::string fname = "no", const std::string lname = "body")
        : Person(fname, lname) {}
    virtual ~PokerPlayer() {}
    int Draw() const { return rand() % 52 + 1; }
};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
    BadDude(const std::string fname = "no", const std::string lname = "body",
            double time = 0.0, int num = 0)
        : Gunslinger(fname, lname, time, num) {}
    virtual ~BadDude() {}
    double Gdraw() const { return Gunslinger::Draw(); }
    int Cdraw() const { return PokerPlayer::Draw(); }
    virtual void Show() const
    {
        Gunslinger::Show();
    }
};

#endif