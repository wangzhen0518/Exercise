#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

std::set<std::string> getname(void)
{
    using namespace std;
    cout << "Enter a name list:\n";
    string str;
    cin >> str;
    //cout << str << endl;
    set<string> name_list;
    while (cin.get() != '\n')
    {
        name_list.insert(str);
        cin >> str;
        //cout << str << endl;
    }
    name_list.insert(str);
    //for (auto temp : name_list)
    //    cout << temp << " ";
    //copy(name_list.begin(), name_list.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
    return name_list;
}

int main()
{
    using namespace std;
    set<string> mar_list = getname();
    set<string> pat_list = getname();
    set<string> total_list;
    total_list.insert(mar_list.begin(), mar_list.end());
    total_list.insert(pat_list.begin(), pat_list.end());
    //merge(mar_list.begin(), mar_list.end(), pat_list.begin(), pat_list.end(), total_list.begin());
    copy(total_list.begin(), total_list.end(), ostream_iterator<string>(cout, " "));

    return 0;
}