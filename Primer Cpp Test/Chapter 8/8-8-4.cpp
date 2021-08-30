#include <iostream>
#include <cstring>

using namespace std;

struct stringy
{
    char *str;
    int ct;
};
void set(stringy &s, char *t)
{
    s.ct = strlen(t);
    s.str = (char *)malloc(sizeof(char) * (s.ct + 1));
    strcpy(s.str, t);
}
void show(const stringy &s, int n = 1)
{
    using std::cout, std::endl;
    for (int i = 0; i < n; i++)
    {
        cout << "str: " << s.str << endl;
        cout << "ct: " << s.ct << endl;
    }
}
void show(const char *s, int n = 1)
{
    using std::cout, std::endl;
    for (int i = 0; i < n; i++)
    {
        cout << "str: " << s << endl;
    }
}

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 2);
    show("Done!");
    return 0;
}