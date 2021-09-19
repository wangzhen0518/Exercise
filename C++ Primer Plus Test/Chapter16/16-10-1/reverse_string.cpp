#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

bool judge(std::string &str);

int main()
{
    using namespace std;
    string str;
    cout << "Enter a string (quit to exit):\n";
    cin >> str;
    while (str != "quit")
    {
        if (judge(str))
            cout << str << ": Yes\n";
        else
            cout << str << ": No\n";
        cout << "Enter a string (quit to exit):\n";
        cin >> str;
    }

    return 0;
}

bool judge(std::string &str)
{
    auto str_reverse = str.rbegin();
    auto str_begin = str.begin();
    for (; str_begin != str.end(); str_begin++, str_reverse++)
        if (*str_begin != *str_reverse)
            return false;
    return true;
}