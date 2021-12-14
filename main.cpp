#include <iostream>

using namespace std;

#include "userProfile.h"

int main()
{
    userProfile user;

 cout << "Welcome! Please login or create an account to continue" << endl;
    cout << "1: login\n"
         << "2: sign up" << endl;
    int login;
    cin >> login;

     if (login == 1)
    {
        if(user.exsists() == true){
            user.menu();
        }
        else{
            cout << "Incorrect input please try again" <<endl;
        }
    }
    else if (login == 2)
    {
        user.saveUser();
    }

    else
    {
        cout << "INVALID INPUT" << endl;
    }
    
}