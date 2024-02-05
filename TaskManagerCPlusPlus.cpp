#include <iostream>
#include "TaskManager.h"

using namespace std;

int main()
{
    char choice;

    while (true)
    {
        cout << "Choose an option.\n1.Create task\n2.Edit task\n3.Get task by number\n4.Exit\nYour choice is: ";
        cin >> choice;

        system("CLS");

        switch (choice)
        {
        case '1':
            TaskManager::CreateTask();
            break;
        case '2':
            TaskManager::CreateTask();
            break;
        case '3':
            TaskManager::GetTask();
            break;
        case '4':
            return 0;
        default:
            cout << "Wrong option." << endl;
            break;
        }
    }
}