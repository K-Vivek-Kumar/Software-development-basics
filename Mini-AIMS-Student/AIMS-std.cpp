#include "test1.h"
#include "test2.h"
#include "test3.h"

using namespace std;

int Open_Portal_Command(int);
int Home_page(string);

int main()
{
     cout << "-- WELCOME !! Mini-AIMS --" << endl
          << ".\n-- THis is only the student version !! Faculty version yet to come !! --\n.\n"
          << "-- running data commands and scanning the resources --" << endl;
     Open_Portal_Command(1);
     cout << "-- Exiting the portal." << endl
     << "-- This was only the student version !! Faculty version yet to come !!" << endl
          << "-- ";
     system("PAUSE");
     return 0;
}