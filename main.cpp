#include <iostream>
using namespace std;

#include "userProfile.h"

int main()
{
    userProfile user;
    
    cout << setw(80) << setfill('-') << "" << setfill(' ') << endl;
    cout << endl;
    cout << "Welcome! Please login or create an account to continue" << endl;
    cout << "1: login" << endl;
    cout << "2: sign up" << endl;
    int login;
    cin >> login;

    if (login == 1)
    {
        user.exsists();
    }
    else if (login == 2)
    {
        user.saveUser();
    }

    else
    {
        cout << "INVALID INPUT" << endl;
    }

    if (user.exsists() == true)
    {
        cout << setw(80) << setfill('-') << "" << setfill(' ') << endl;
        cout << endl;
        cout << "Welcome to the worlds most ok nutrient calculator" << endl;
        cout << "How would you like to continue?" << endl;

        cout << "1: add food" << endl;
        cout << "2: remove food" << endl;
        cout << "3: change username" << endl;
        cout << "4: display current macros" << endl;
        cout << "5: exit" << endl;
        int condition;
        cin >> condition;

        switch (condition)
        {
        case 1:
            user.addMeal();
            break;
        case 2:
        // todo remove food
            break;

        case 3:
            break;
        // todo change UN
        case 4:
            user.printUser();
            break;
        case 5:
            return 0;
            break;
        }
    }
}
