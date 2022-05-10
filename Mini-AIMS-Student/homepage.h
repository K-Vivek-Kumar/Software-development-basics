#ifndef homepage
#define homepage

#include <fstream>
#include <iostream>
#include <string>
using namespace std;


#include "support.h"
#include "test1.h"
#include "U1.h"

int Open_Portal_Command(int);
int Home_page(string);

int Home_page(string user_space)
{
    for (int i = 0; i < 20; i++)
    {
        system("cls");
        cout << "-- Mini-AIMS portal --" << endl
             << ".\n.\n.\n"
             << "-- Course command > > > ";
        string command;
        cin >> command;
        if (command == "logout")
        {
            system("cls");
            cout << "-- Mini-AIMS portal --" << endl
                 << ".\n.\n.\n"
                 << "-- Exiting the course command. Logout successful !" << endl;
            Open_Portal_Command(1);
        }
        else if (command == "add-c")
        {
            system("cls");
            cout << "-- Mini-AIMS portal --" << endl
                 << ".\n.\n.\n"
                 << "-- Course addition > > >" << endl;
            Add_Course(user_space);
        }
        else if (command == "c-status")
        {
            system("cls");
            cout << "-- Mini-AIMS portal --" << endl
                 << ".\n.\n.\n"
                 << "-- Course status > > >" << endl;
            Course_status(user_space);
        }
        else if (command == "running-c")
        {
            system("cls");
            cout << "-- Mini-AIMS portal --" << endl
                 << ".\n.\n.\n"
                 << "-- Courses running > > >" << endl;
            Running_courses(user_space);
        }
    }
    cout << "-- Session has expired --";
    cout << "-- Login again --";
    return 0;
}

#endif