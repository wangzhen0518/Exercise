#include <iostream>
#include <fstream>

int main()
{
    using namespace std;
    string file1, file2, file3;
    cout << "Enter three file names:\n";
    cin >> file1 >> file2 >> file3;
    ifstream fin1(file1);
    ifstream fin2(file2);
    ofstream fout(file3);
    string str1, str2;
    while (!fin1.eof() && !fin2.eof())
    {
        getline(fin1, str1);
        getline(fin2, str2);
        fout << str1 << " " << str2 << endl;
    }
    if (!fin1.eof())
    {
        getline(fin1, str1);
        fout << str1 << endl;
    }
    if (!fin2.eof())
    {
        getline(fin2, str2);
        fout << str2 << endl;
    }
    return 0;
}