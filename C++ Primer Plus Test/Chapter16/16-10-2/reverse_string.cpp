#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <cctype>

bool judge(const std::string &str);

int main()
{
    using namespace std;
    string str;
    cout << "Enter a string (quit to exit):\n";
    getline(cin, str);
    while (str != "quit")
    {
        if (judge(str))
            cout << str << ": Yes\n";
        else
            cout << str << ": No\n";
        cout << "Enter a string (quit to exit):\n";
        getline(cin, str);
    }

    return 0;
}

std::string first_handle(const std::string &str)
{
    std::string temp;
    int j = 0;
    for (int i = 0; i < str.length(); i++)
        if (isalpha(str[i]))
            temp.push_back(tolower(str[i]));
    return temp;
}

bool judge(const std::string &str)
{
    std::string temp_str = first_handle(str);
    auto str_reverse = temp_str.rbegin();
    auto str_begin = temp_str.begin();
    for (; str_begin != temp_str.end(); str_begin++, str_reverse++)
        if (*str_begin != *str_reverse)
            return false;
    return true;
}