#include <iostream>

using namespace std;

#include "userProfile.h"



int main(){
    int input;
    bool m = true, test=true;
    userProfile user;

    for(int x = 0; x < 15; x++)
        cout << "\n";
    cout << "Welcome to the worlds most ok nutrient calculator! Please enter the number of your desired choice." << endl;
    cout << "\t1: login" << endl
         << "\t2: sign up" << endl;
    for(int x = 0; x < 15; x++)
        cout << "\n";
    cin >> input;
    
    switch (input){
    case 2: 
        user.saveUser();
    case 1:
        if(user.exists() == true){
            while(m){
                cout << setw(90) << setfill('-') << "" << setfill(' ') << endl;
                cout << "\n\t\tMenu: Please enter your desired choice's number" << endl;
                cout << "\t\t\t1: add food" << endl;
                cout << "\t\t\t2: remove food" << endl;
                cout << "\t\t\t3: change username" << endl;
                cout << "\t\t\t4: display current macros" << endl;
                cout << "\t\t\t5: Exit" << endl;
                for(int x = 0; x < 15; x++)
                    cout << "\n";
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