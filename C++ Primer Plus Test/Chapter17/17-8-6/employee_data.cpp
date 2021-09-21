#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <memory>
#include "emp.h"

static const int MAX = 3;
static const int LINE_MAX = 50;

void show_data(std::ifstream &fin)
{
    using namespace std;
    fin.seekg(0);
    vector<shared_ptr<abstr_emp>> pc;
    int kind;
    abstr_emp *temp;
    while (!fin.eof())
    {
        fin >> kind;
        fin.get();
        switch (empKind(kind))
        {
        case empKind::_employee:
            temp = new employee;
            temp->getall(fin);
            break;
        case empKind::_manager:
            temp = new manager;
            temp->getall(fin);
            break;
        case empKind::_fink:
            temp = new fink;
            temp->getall(fin);
            break;
        case empKind::_high_fink:
            temp = new highfink;
            temp->getall(fin);
            break;
        }
        pc.push_back(shared_ptr<abstr_emp>(temp));
        while (fin.peek() == '\n')
            fin.get();
    }
    for (auto emp : pc)
    {
        emp->ShowAll();
        cout << endl;
    }
    fin.clear();
}

std::shared_ptr<abstr_emp> add_data(std::ofstream &fout)
{
    using namespace std;
    cout << "Choose a kind of data to create:\n";
    cout << left;
    cout << setw(15) << "1: employee" << setw(15) << "2: manager" << endl
         << setw(15) << "3: fink" << setw(15) << "4: high_fink" << endl;
    int t;
    cin >> t;
    shared_ptr<abstr_emp> temp;
    switch (empKind(t))
    {
    case empKind::_employee:
        temp = shared_ptr<abstr_emp>(new employee);
        temp->SetAll();
        break;
    case empKind::_manager:
        temp = shared_ptr<abstr_emp>(new manager);
        temp->SetAll();
        break;
    case empKind::_fink:
        temp = shared_ptr<abstr_emp>(new fink);
        temp->SetAll();
        break;
    case empKind::_high_fink:
        temp = shared_ptr<abstr_emp>(new highfink);
        temp->SetAll();
        break;
    default:
        cout << "wrong input, try again\n";
        break;
    }
    temp->writeall(fout);
    fout << std::endl;
    return temp;
}

void initial_data(const char *filename)
{
    using namespace std;
    shared_ptr<abstr_emp> pc[MAX];
    ofstream fout(filename);
    if (fout.is_open())
    {
        for (int i = 0; i < MAX; i++)
        {
            pc[i] = add_data(fout);
        }
        for (int i = 0; i < MAX; i++)
        {
            pc[i]->ShowAll();
            cout << endl;
        }
        fout.close();
    }
    else
    {
        cerr << "Cannot open the file\n";
        exit(EXIT_FAILURE);
    }
}

int main()
{
    using namespace std;
    const char *filename = "test.dat";
    ifstream fin(filename);
    if (fin.is_open())
        show_data(fin);
    else
        initial_data(filename);
    cout << "Do you want to add new data? (yes/no)\n";
    string choose;
    bool flag = false;
    cin >> choose;
    if (choose == "yes")
        flag = true;
    while (choose == "yes")
    {
        ofstream fout(filename, ios_base::app | ios_base::out);
        add_data(fout);
        cout << "Do you still want to add new data? (yes/no)\n";
        cin >> choose;
        fout.close();
    }
    if (flag)
    {
        cout << "Now the data:\n";
        show_data(fin);
    }
    fin.close();
    cout << "Bye\n";
    return 0;
}