#include <iostream>

using namespace std;

#include "userProfile.h"
#include "foodLog.h"


int main() {  
    int input;
    bool m = true;
    userProfile user;
    foodLog driver;

    cout << "\n\n\n\n\nWelcome! Please login or create an account to continue." << endl;
    cout << "\t1: login" << endl
         << "\t2: sign up" << endl;
    cin >> input;

    switch (input){
    case 2: 
        user.saveUser();
    case 1:
        if(user.exists() == true){
            cout << "\n\n\n\n\n\n\n\n\n\n\n\nWelcome to the worlds most ok nutrient calculator" << endl;
            while(m){
                cout << setw(80) << setfill('-') << "" << setfill(' ') << endl;
                cout << "\nHow would you like to continue?" << endl;
                cout << "\t\t1: add food" << endl;
                cout << "\t\t2: remove food" << endl;
                cout << "\t\t3: change username" << endl;
                cout << "\t\t4: display current macros" << endl;
                cout << "\t\t5: Exit" << endl;
                cin >> input;
                switch (input)
                {
                case 1:
                    user.addMeal();
                    break;
                case 2:
                    cout << "This feature is not yet available" << endl;
                    break;
                case 3:
                    user.changeName();
                    break;
                case 4:
                    user.printUser();
                    break;
                case 5:
                    cout << "Thanks for using the world's most ok macronutrient calculator" <<endl;
                    m = false;
                    break;
                default:
                    cout << "Invalid Input, please try again." << endl;
                    break;
                }
            }
        }
        else{
            cout << "Incorrect input please try again" <<endl;
        }
        break;
    default:
        cout << "INVALID INPUT" << endl;
    }
}