#include <iostream>

int main()
{
    using namespace std;
    int num = 0;
    while (cin.peek() != '$')
    {
        cin.get();
        num++;
    }
    cout << "There are " << num << " letters.\n";
    return 0;
}