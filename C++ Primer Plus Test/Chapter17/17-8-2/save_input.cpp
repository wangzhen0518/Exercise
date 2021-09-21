#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    using namespace std;
    if (argc == 1)
    {
        cerr << "Wrong parameter number\n";
        exit(EXIT_FAILURE);
    }
    ofstream fout(argv[1]);
    if (fout.is_open())
    {
        char c;
        while ((c = cin.get()) != EOF)
            fout << c;
    }
    else
    {
        cerr << "Can not open the file.\n";
        exit(EXIT_FAILURE);
    }
    fout.close();
    return 0;
}