#ifndef TASK_MANAGER_H_
#define TASK_MANAGER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>

using namespace std;

namespace TaskManager
{
    void CreateTask()
    {
        try
        {
            ofstream newFile("C:\\Tasks.txt", ios::app);
            int num = 0;
            string task, state;
            cout << "Write number of task (needed to get task from file): ";
            cin >> num;
            cout << "Write your task: ";
            cin.ignore();
            getline(cin, task);
            cout << "Write state of yout task (it can be anything, but be sure not to forget it): ";
            cin >> state;

            newFile << num << " " << task << " " << state << endl;
            newFile.close();
        }
        catch (exception ex)
        {
            cerr << ex.what();
        }
    }

    void EditTask()
    {
        fstream file("C:\\Tasks.txt", ios::in | ios::out);

        char number;
        string line, old_line, new_line, task, state;
        streampos pos;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        cout << "Which task do you want to change? Write number of task: ";
        cin >> number;
        while (getline(file, line))
        {
            char num = line[0];
            if (num == number)
            {
                pos = file.tellg();
                line = old_line;
            }
            else
            {
                cout << "Can't find task by number.";
                file.close();
            }
            break;
        }
        cout << "Write task: ";
        getline(cin, task);
        cout << "Write state: ";
        cin >> state;
        new_line = number + " " + task + " " + state;
        cout << "Your new task looks like: " << new_line;

        if (pos != 0)
        {
            file << new_line;
            cout << "Task is changed.";
            file.close();
        }
        else
        {
            cout << "Lost pos.";
            file.close();
        }
    }

    void GetTask()
    {
        ifstream file("C:\\Tasks.txt");
        string line;
        char number;
        int count = 0;
        while (getline(file, line))
        {
            char num = line[0];
            cout << num << " ";
            count += 1;
        }
        cout << "File contains " << count << " tasks." << endl;;
        cout << "Write number of task you want to see: ";
        cin >> number;

        while (getline(file, line))
        {
            char num = line[0];
            if (number = num)
            {
                cout << line.substr(2);
                file.close();
            }
        }
    }
}

#endif