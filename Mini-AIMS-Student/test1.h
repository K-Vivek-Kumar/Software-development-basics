#ifndef test
#define test

#include <iostream>
#include <cstring>

#include "test2.h"
#include "test3.h"
#include "support.h"
#include "homepage.h"
#include "U1.h"
#include "U2.h"

using namespace std;

int Open_Portal_Command(int);
int Home_page(string);

int Match_Found(string to_be_found)
{
    system("cls");
    cout << "-- Mini-AIMS portal --" << endl
         << ".\n.\n.\n"
         << endl;
    string sec_key_mentioned;
    cout << "-- Re-enter the available security key with you : ";
    cin >> sec_key_mentioned;
    system("cls");
    cout << "-- Mini-AIMS portal --" << endl
         << ".\n.\n.\n"
         << endl;
    if (sec_key_mentioned != to_be_found)
    {
        return 2;
    }

    ifstream file_text("pending_std_line.txt");
    string x;
    int line = 1;
    if (file_text.is_open())
    {
        while (getline(file_text, x))
        {
            if (x.find(sec_key_mentioned, 0) != string::npos)
            {
                {
                    cout << "-- An available key is found.\n -- Setting up your account." << endl;
                    Acc_set_up();
                }

                line++;
            }
            file_text.close();
        }
    }
    else
    {
        cout << "-- Entered security-key isn't a valid one, contact the admin." << endl;
        return 1;
    }
    return 0;
}

int Verify_Student()
{
    string Security_Key_Student;
    cout << "-- Looking for pending Security-Ids" << endl;
    cout << "-- Enter the Security-Id you have : ";
    cin >> Security_Key_Student;
    if (Match_Found(Security_Key_Student) == 0)
    {
        cout << "-- A step towards the set up\n";
        cout << "-- Under setting up construction";
        Acc_set_up();
    }
    else
    {
        cout << "-- It is not a valid Security-Id. Either try again or contact the admin." << endl;
    }
    return 0;
}

int Establish_a_student()
{
    system("cls");
    cout << "-- Mini-AIMS portal --" << endl
         << ".\n.\n.\n"
         << endl;
    int stat;
    cout << "-- If you have a Security-Id then press 1, else press 0 for generating one" << endl;
    cin >> stat;
    system("cls");
    cout << "-- Mini-AIMS portal --" << endl
         << ".\n.\n.\n"
         << endl;
    if (stat == 1)
    {
        Verify_Student();
    }
    else if (stat == 0)
    {
        New_Student();
    }
    return 0;
}

int New_User()
{
    int status;
    cout << "-- Encountered a new student !! Enter 1 if yes, else enter 0" << endl;
    cin >> status;
    system("cls");
    cout << "-- Mini-AIMS portal --" << endl
         << ".\n.\n.\n"
         << endl;
    if (status == 1)
    {
        Establish_a_student();
    }
    else if (status == 0)
    {
        int stat2;
        cout << "-- Press 1 to go ahead, else 0 to leave the site." << endl;
        cin >> stat2;
        system("cls");
        cout << "-- Mini-AIMS portal --" << endl
             << ".\n.\n.\n"
             << endl;
        if (stat2 == 1)
        {
            cout << "-- If you are expecting to come up being an instructor here," << endl
                 << "-- plz contact the admin or dean by mailing at <none>@iith.ac.in." << endl;
        }
    }
}

int Open_Portal_Command(int a)
{
    if (a == 1)
    {
        char User_name[15];
        cout << "-- Active user found" << endl;
        cout << "-- every command is case-sensitive." << endl;
        cout << "-- Enter the command requirements : ";
        cin >> User_name;
        system("cls");
        cout << "-- Mini-AIMS portal --" << endl
             << ".\n.\n.\n"
             << endl;
        if (strcmp(User_name, "new") == 0)
        {
            cout << "-- A new user mentioning" << endl;
            New_User();
        }
        else if (strcmp(User_name, "data") == 0)
        {
            cout << "-- Checking out all the available data in the server wihtout login" << endl;
            ifstream file_text("user_name_list.txt");
            string x;
            int line = 1;
            if (file_text.is_open())
            {
                while (getline(file_text, x))
                {
                    if (x.find("s", 0) != string::npos)
                    {
                        {
                            cout << "-- Username (ROLL) : " << x << " : " << line << endl;
                        }

                        line++;
                    }
                }
                file_text.close();
            }
            system("PAUSE");
        }
        else if (strcmp(User_name, "login") == 0)
        {
            Login_user();
        }
        cout << "-- Enter 1 to remain in the portal : ";
        int dee;
        cin >> dee;
        if (dee == 1)
        {
            Open_Portal_Command(dee);
        }
    }
    else
    {
        server_lag_issue_1();
    }
}

#endif