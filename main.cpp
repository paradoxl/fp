#include <iostream>

using namespace std;

#include "userProfile.h"
#include "foodLog.h"


int main()
{
    userProfile user;
    foodLog driver;

 cout << "Welcome! Please login or create an account to continue" << endl;
    cout << "1: login\n"
         << "2: sign up" << endl;
    int login;
    cin >> login;

     if (login == 1)
    {
        if(user.exsists() == true){
            
           cout << "welcome to the worlds most ok nutrient calculator" << endl;
        cout << "how would you like to continue?" << endl;

        cout << "1: add food" << endl;
        cout << "2: remove food" << endl;
        cout << "3: change username" << endl;
        cout << "4: display current macros" << endl;
        cout << "5: Exit" << endl;
        int condition;
        cin >> condition;

        switch (condition)
        {
        case 1:
            driver.addMeal();
            break;
        case 2:
            cout << "This feature is not yet available" << endl;
            break;
        case 3:
            user.changeName();
            break;
        case 4:
            driver.printUser();
            break;
        case 5:
            cout << "Thanks for using the world's most ok macronutrient calculator" <<endl;
            break;
        }
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