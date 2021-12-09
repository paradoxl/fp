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

        case 3: // change username
            {
              string filename, name, Newname, newContent = "";
              string word, temp;
              int noOfWords = 0, noOfReplacements = 0, matched, replaced;

              cout << setw(80) << setfill('-') << "" << setfill(' ') << endl;
              cout << endl;
              cout << "Enter a text file name: ";
              cin >> filename;
              cout << "Please type your old username: ";
              cin >> name;
              cout << "Please type your new username: ";
              cin >> Newname;
              cout << "\n";

              ifstream inFile;
              inFile.open(filename.c_str());

              if (!inFile) //If file cannot be opened
                cout << "File cannot be opened." << endl;

              else {

                string content((istreambuf_iterator < char > (inFile)), (istreambuf_iterator < char > ()));
                inFile.close();

                for (int i = 0; content[i] != '\0'; i++) {
                  if (content[i] == ' ' && i != 0)
                    noOfWords += 1;
                  matched = 1;
                  replaced = 0;

                  if (content[i] == name[0]) {
                    temp = "";

                    for (int j = 0; name[j] != '\0'; j++) {
                      temp += content[i];
                      if (content[i] != name[j]) {
                        matched = 0;
                      }
                      i = i + 1;
                    }
                    i--;

                    if (matched == 1) {
                      newContent += Newname;
                      noOfReplacements++;
                    } else {
                      newContent += temp;
                    }
                  } else {
                    newContent += content[i];
                  }
                }
                noOfWords += 1;
                ofstream outFile;
                outFile.open(filename.c_str());
                outFile << newContent << endl;
                outFile.close();
              }
              return 0;
            }
            break;

        case 4:
            user.printUser();
            break;
        case 5:
            return 0;
            break;
        }
    }
}
