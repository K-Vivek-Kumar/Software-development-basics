#ifndef test2
#define test2

#include <iostream>
#include <cstring>
#include <fstream>

#include "test1.h"
#include "test3.h"

using namespace std;

int Open_Portal_Command(int);
int Home_page(string);

int New_Student()
{
    cout << "-- Generating a new key for you.\n";

    cout << "-- Enter your email-id : ";
    string email_id;
    cin >> email_id;

    string a;
    getline(cin, a);

    cout << "-- Enter your name : ";
    string user_name;
    getline(cin, user_name);

    system("cls");
    cout << "-- Mini-AIMS portal --" << endl
         << ".\n.\n.\n"
         << endl;
    cout << "-- Name mentioned : " << user_name << endl;
    cout << "-- Email entered : " << email_id << endl;

    system("PAUSE");
    system("cls");

    fstream my_file;
    my_file.open("pending_std_line.txt", ios::app);
    system("cls");
    cout << "-- Mini-AIMS portal --" << endl
         << ".\n.\n.\n"
         << endl;
    cout << "-- The tentative key is generated for you, a mail will reach you out" << endl;
    cout << "-- Wait for an admin response at your given email id.\n";
    my_file << user_name << " : " << email_id << " : "
            << "generated key to be updated.\n"
            << "Key Updation : " << endl;
    my_file.close();
    return 0;
}

#endif