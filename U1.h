#ifndef U1
#define U1

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "homepage.h"
#include "test1.h"

int Open_Portal_Command(int);
int Home_page(string);

class Student_profile
{
public:
    string name;
    string date_of_birth;
    string course;
};

int Running_courses(string user_space)
{
    cout << "-- Enter the type of course list, you want : ";
    string course_type;
    cin >> course_type;
    system("cls");
    cout << "-- Mini-AIMS portal --" << endl
         << ".\n.\n.\n"
         << "-- Course command > > > ";
    cout << "-- Entered course type is " << course_type << endl;
    cout << "-- Enter 1 to check its lists" << endl;
    int dem;
    cin >> dem;
    if (dem == 1)
    {
        system("cls");
        cout << "-- Mini-AIMS portal --" << endl
             << ".\n.\n.\n"
             << "-- Course command > > > ";
        cout << "\n-- Showing all available courses > > >" << endl;
        if (course_type != "all")
        {
            ifstream file_text(user_space);
            string x;
            int line = 1;
            if (file_text.is_open())
            {
                while (getline(file_text, x))
                {
                    if (x.find(course_type, 0) != string::npos)
                    {
                        {
                            cout << "-- Status : " << x << " : " << line << endl;
                        }

                        line++;
                    }
                }
                file_text.close();
            }
            system("PAUSE");
        }
        else if (course_type == "all")
        {
            ifstream file_text(user_space);
            string x;
            int line = 1;
            if (file_text.is_open())
            {
                while (getline(file_text, x))
                {
                    if (x.find("accepted", 0) != string::npos)
                    {
                        {
                            cout << "-- Status : " << x << " : " << line << endl;
                        }

                        line++;
                    }
                    if (x.find("pending", 0) != string::npos)
                    {
                        {
                            cout << "-- Status : " << x << " : " << line << endl;
                        }

                        line++;
                    }
                }
                file_text.close();
            }
            system("PAUSE");
        }
    }
    Home_page(user_space);
    return 0;
}

int Add_Course(string user_space)
{
    Student_profile Student;
    cout << "-- Enter the course id : ";
    string course_type;
    cin >> course_type;
    system("cls");
    cout << "-- Mini-AIMS portal --" << endl
         << ".\n.\n.\n"
         << "-- Course command > > > ";
    cout << "-- Entered course id is " << course_type << endl;
    cout << "-- Enter 1 to enroll for this course" << endl;
    int dem;
    cin >> dem;
    if (dem == 1)
    {
        Student.course = course_type;
        fstream my_file;
        my_file.open(user_space, ios::app);

        system("cls");
        cout << "-- Mini-AIMS portal --" << endl
             << ".\n.\n.\n"
             << endl;
        cout << "-- The course registration is set to pending" << endl;
        cout << "-- Wait for course instructor to accept your welcome --\n";
        my_file << "\n"
                << course_type << " : "
                << "pending"
                << endl;
        my_file.close();

        system("PAUSE");
    }
    Home_page(user_space);
    return 0;
}

int Course_status(string user_space)
{
    cout << "-- Enter the course id : ";
    string course_type;
    cin >> course_type;
    system("cls");
    cout << "-- Mini-AIMS portal --" << endl
         << ".\n.\n.\n"
         << "-- Course command > > > ";
    cout << "-- Entered course id is " << course_type << endl;
    cout << "-- Enter 1 to check its status" << endl;
    int dem;
    if (dem == 1)
    {
        system("cls");
        cout << "-- Mini-AIMS portal --" << endl
             << ".\n.\n.\n"
             << "-- Course command > > > ";

        ifstream file_text(user_space);
        string x;
        int line = 1;
        if (file_text.is_open())
        {
            while (getline(file_text, x))
            {
                if (x.find(course_type, 0) != string::npos)
                {
                    {
                        cout << "-- Status : " << x << " : " << line << endl;
                    }

                    line++;
                }
            }
            file_text.close();
        }
        system("PAUSE");
    }
    Home_page(user_space);
    return 0;
}

#endif