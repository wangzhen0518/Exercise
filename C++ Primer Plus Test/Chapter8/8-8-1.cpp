#include <iostream>

void print(const std::string &s, int n = 1)
{
    if (n != 0)
    {
        std::cout << n << ": " << s << std::endl;
        print(s, n - 1);
    }
    else
        return;
}

int main()
{
    std::string s("陈禹岚");
    print(s);
    return 0;
}