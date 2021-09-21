#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class Store
{
private:
    std::string str;
    std::ofstream *m_os;

public:
    Store(std::ofstream &os) : m_os(&os) {}
    ~Store() {}
    bool operator()(const std::string &str)
    {
        size_t len = str.size();
        if(m_os->is_open())
        {
            m_os->write((char *)(&len), sizeof(size_t));
            m_os->write(str.c_str(), len);
            return true;
        }
        else
            return false;
    }
};

inline void ShowStr(const std::string &str)
{
    std::cout << str << std::endl;
}

void GetStrs(std::ifstream &fin, std::vector<std::string> &ar) //TODO:
{
    size_t len;
    char *temp;
    while (!fin.eof())
    {
        fin.read((char *)(&len), sizeof(size_t));
        temp = new char[len];
        fin.read(temp, len);
        ar.push_back(temp);
        delete[] temp;
    }
}

int main()
{
    using namespace std;
    vector<string> vostr;
    string temp;

    //acquire strings
    cout << "Enter strings (empty line to quit):\n";
    while (getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    //store in a file
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    //recover file contents
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}