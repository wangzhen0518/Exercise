#include <iostream>
#include <fstream>

//copy file1 to file2
int main(int argc, char *argv[])
{
    using namespace std;
    if (argc <= 2)
    {
        cerr << "Wrong parameter number\n";
        exit(EXIT_FAILURE);
    }
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    if (fout.is_open() && fin.is_open())
    {
        char c;
        c = fin.get();
        while (!fin.eof())
        {
            fout << c;
            c = fin.get();
        }
    }
    else
    {
        cerr << "Can not open the file.\n";
        exit(EXIT_FAILURE);
    }
    fout.close();
    return 0;
}