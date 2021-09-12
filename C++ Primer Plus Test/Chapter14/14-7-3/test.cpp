#include <iostream>
#include <cstring>
#include "Worker.h"
#include "QueueTp.h"

const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    QueueTp<Worker *> lolas(SIZE);

    int ct;
    Worker *temp;
    while(!lolas.isfull())
    {
        char choice;
        cout << "Enter the employee category:\n"
             << "w: waiter  s: singer  "
             << "t: singing waiter  q: quit\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'w':
            temp = new Waiter;
            break;
        case 's':
            temp = new Singer;
            break;
        case 't':
            temp = new SingingWaiter;
            break;
        }
        cin.get();
        temp->Set();
        lolas.push(temp);
    }

    cout << "\nHere is your staff:\n";
    int i;
    while(!lolas.isempty())
    {
        cout << endl;
        lolas.pop(temp);
        temp->Show();
        delete temp;
    }
    cout << "Bye.\n";
    // cin.get();
    // cin.get();
    return 0;
}
