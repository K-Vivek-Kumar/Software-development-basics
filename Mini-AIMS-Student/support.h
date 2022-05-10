#ifndef support
#define support

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "test1.h"
#include "homepage.h"

int Open_Portal_Command(int);
int Home_page(string);

int Open_user_page(string file_name)
{
    system("cls");
    cout << "-- Mini-AIMS portal --" << endl
         << ".\n.\n.\n"
         << endl;
    string pass_word;
    cout << "-- Enter the password : ";
    cin >> pass_word;
    system("cls");
    cout << "-- Mini-AIMS portal --" << endl
         << ".\n.\n.\n"
         << endl;

    ifstream file_text(file_name);
    string x;
    int line = 1;
    if (file_text.is_open())
    {
        while (getline(file_text, x) && (line == 1))
        {
            if (x.find(pass_word, 0) != string::npos)
            {
                {
                    cout << "-- Login was successful !!" << endl;
                    cout << "-- Press 1 to move into operation monitor --" << endl;
                    int dem;
                    cin >> dem;
                    if (dem == 1)
                    {
                        Home_page(file_name);
                    }
                }

                line++;
            }
            file_text.close();
        }
    }
    return 0;
}

int Login_user()
{
    string getcontent;
    string search;
    cout << "-- Check it : Username : ";
    cin >> search;

    ifstream openfile("user_name_list.txt");

    if (openfile.is_open())
    {

        while (!openfile.eof())
        {
            getline(openfile, getcontent);
            if (search == getcontent)
            {
                system("cls");
                cout << "-- Mini-AIMS portal --" << endl
                     << ".\n.\n.\n"
                     << endl;
                cout << "-- The entered user name is found to be " << getcontent << endl
                     << "-- Press 1 for confirmation" << endl;
                int dem;
                cin >> dem;
                if (dem == 1)
                {
                    Open_user_page(search);
                }
            }
            else
            {
                cout << "-- Entered an invalid username..." << endl;
                break;
            }
        }
        openfile.close();
    }
    return 0;
}

#endif