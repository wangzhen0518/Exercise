#include <iostream>
#include <iomanip>

int main()
{
    using namespace std;
    string name;
    double wages;
    double num;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your hourly wages: ";
    cin >> wages;
    cout << "Enter number of hours worked: ";
    cin >> num;
    cout << "First format:\n"
         << right << fixed
         << setw(20) << name << ": $"
         << setw(10) << setprecision(2) << wages << ":"
         << setw(5) << setprecision(1) << num;
    cout << endl;
    cout << "Second format:\n"
         << left << fixed
         << setw(20) << name << ": $" << setw(10) << setprecision(2) << wages << ":"
         << setw(5) << setprecision(1) << num;
    cout << endl;

    return 0;
}