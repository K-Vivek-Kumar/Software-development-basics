#ifndef U2
#define U2

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "test1.h"

int Acc_set_up()
{
    system("cls");
    cout << "-- Mini-AIMS portal --" << endl
         << ".\n.\n.\n"
         << endl;
    cout << "-- Enter your user-name : ";
    string user_name_page;
    cin >> user_name_page;
    cout << "-- Enter the password : ";
    string pass_word;
    cin >> pass_word;
    fstream my_file;
    my_file.open(user_name_page, ios::app);

    system("cls");
    cout << "-- Mini-AIMS portal --" << endl
         << ".\n.\n.\n"
         << endl;
    cout << "-- Account set-up is done" << endl;
    my_file << "password : " << pass_word << endl;
    my_file.close();

    my_file.open("user_name_list.txt", ios::app);
    my_file << user_name_page << endl;
    my_file.close();
    return 0;
}

#endif