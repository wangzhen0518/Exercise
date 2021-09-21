#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

std::set<std::string> getname(const char *filename)
{
    using namespace std;
    set<string> name_list;
    ifstream fin(filename);
    if (fin.is_open())
    {
        string str;
        while (getline(fin, str) && str.size() > 0)
        {
            name_list.insert(str);
        }
    }
    else
    {
        cerr << "Cannot open the file\n";
        exit(EXIT_FAILURE);
    }
    return name_list;
}

inline void printname(const std::string &list)
{
    std::cout << list << std::endl;
}

int main()
{
    using namespace std;
    const char *file1 = "mat.dat";
    const char *file2 = "pat.dat";
    const char *file3 = "matnpat.dat";
    set<string> mat_list = getname(file1);
    set<string> pat_list = getname(file2);
    cout << "mat.dat:\n";
    for_each(mat_list.begin(), mat_list.end(), printname);
    cout << "\npat.dat:\n";
    for_each(pat_list.begin(), pat_list.end(), printname);

    set<string> total_list(mat_list);
    total_list.insert(pat_list.begin(), pat_list.end());
    cout << "\ntotal:\n";
    for_each(total_list.begin(), total_list.end(), printname);

    ofstream fout(file3);
    if (fout.is_open())
    {
        for (string str : total_list)
        {
            fout << str << endl;
        }
    }
    else
    {
        cerr << "Cannot open the file\n";
        exit(EXIT_FAILURE);
    }
    return 0;
}