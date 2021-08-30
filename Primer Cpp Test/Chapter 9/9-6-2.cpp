// static.cpp -- using a static local variable
#include <iostream>

// function prototype
void strcount(const std::string &str);

int main()
{
    using namespace std;
    string input;
    char next;

    cout << "Enter a line:\n";
    cin >> input;
    while (input != "")
    {
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        cin >> input;
    }
    cout << "Bye\n";
    // code to keep window open for MSVC++
    /*
cin.clear();
    while (cin.get() != '\n')
        continue;
    cin.get();
*/
    return 0;
}

void strcount(const std::string &str)
{
    using namespace std;
    static int total = 0; // static local variable
    int count = 0;        // automatic local variable

    cout << "\"" << str << "\" contains ";
    count = str.length();
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}
