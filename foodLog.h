#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

#include "projectunorderedLinkedList.h"

using namespace std;

class foodLog
{
private:
    unorderedLinkedList<string> dailyLog;
    void calculateTotals();    
    float calories;
    float proteins;
    float carbs;
    float fats;

public:
    void addMeal();
    void deleteMeal();
    float getCalories();
    float getProteins();
    float getCarbs();
    float getFats();
    foodLog();
    ~foodLog();
};

void foodLog::calculateTotals(){
    linkedListIterator<string> listIt;
    
    proteins = 0;
    carbs = 0;
    fats = 0;
    listIt = dailyLog.begin();
    while(listIt != dailyLog.end()){
        proteins = proteins + stof(listIt.returnArrayElement(1));
        carbs = carbs + stof(listIt.returnArrayElement(2));
        fats = fats + stof(listIt.returnArrayElement(3));
        ++listIt;
    }

    calories = proteins * 9 + carbs * 4 + fats * 4;
}

//adds food to program
void foodLog::addMeal()
{
    ifstream inFile;
    string search, proteinStr, carbStr, fatStr, foodName;
    int x=0;

    inFile.open("food.txt");

    if (!inFile){
        cout << "Our database is currently unreachable." << endl;
    }
    else{
        for(int x = 0; x < 15; x++)
            cout << "\n";
        cout << "Please enter a food you want to add" << endl;
        for(int x = 0; x < 15; x++)
                    cout << "\n";
        cin >> search;

        int curLine;
        string line;
        string temp;

        for(int x = 0; x < 15; x++)
                    cout << "\n";
        while (getline(inFile, line))
            if (line.find(search, 0) != string::npos)
                x++;
        
        inFile.close();
        
        if(x==1){
            inFile.open("food.txt");
            while (getline(inFile, line)){
                if (line.find(search, 0) != string::npos){
                    cout << "found: " << search << " Macronutrients " << line << endl;
                }
            }
            inFile.close();
            inFile.open("food.txt");
            while (getline(inFile, line)){
                inFile >> temp;
                if (temp == search){                    
                    foodName = temp;
                    inFile >> proteinStr;
                    inFile >> carbStr;
                    inFile >> fatStr;
                    dailyLog.insertFirst(foodName, proteinStr, carbStr, fatStr);
                    x=-1;
                }
            }
            inFile.close();
        }

        

        while (x>1 || x == 0){
            inFile.open("food.txt");
            while (getline(inFile, line)){
                if (line.find(search, 0) != string::npos){
                    cout << "found: " << search << " Macronutrients " << line << endl;
                }
            }
            inFile.close();
            if(x==0)
                cout << "The food you entered is not apart of our database. "
                    << "Please  try again." << endl;
            else
                cout << "Please refine your search." << endl;
            cin >> search;
            inFile.open("food.txt");
            while (getline(inFile, line)){
                inFile >> temp;
                if (temp == search){
                    foodName = temp;
                    inFile >> proteinStr;
                    inFile >> carbStr;
                    inFile >> fatStr;
                    dailyLog.insertFirst(foodName, proteinStr, carbStr, fatStr);
                    x = -1;
                }

                curLine++;
                if (line.find(search, 0) != string::npos){
                    cout << "found: " << search << " Macronutrients " << line << endl;
                }
            }

            inFile.close();
        }

        cout << "Would you like to add another food to this meal?(Y/N) " << endl;
        string additionalFood;
        cin >> additionalFood;

        if (additionalFood == "Y" || additionalFood == "y")
        {
            addMeal();
        }

        else{
            calculateTotals();
        }
    }
}   

// removes food from user foodLog

void foodLog::deleteMeal() {
    string input, m;
    bool flag = true;
    cout << "Today's Food Log: " << endl;
    dailyLog.print();
    cout << "Please enter the name of the food you wish to remove: ";

    while(flag){
        cin >> input;
        if(input == "cancel" || input == "Cancel")
            flag = false;
        if(!dailyLog.search(input)){
            cout << "Today's Food Log: " << endl;
            dailyLog.print();
            cout << "Food not found in your log. Please try again or enter cancel to exit.";
        }
        else{
            dailyLog.deleteNode(input);
            cout << input << " has been removed. Would you like to remove another item?(Y/N)";
            cin >> m;
            if(m == "y" || m == "Y"){
                cout << "Today's Food Log: " << endl;
                dailyLog.print();
            }
            else{
                flag = false;
            }
        }
    }
    /*
    dailyLog.deleteNode()
    nodeType<string> *current;       // pointer to traverse the list
    nodeType<string> *trailCurrent;  // pointer just before current
    bool found;

    //const Type& toDelete

    ifstream inFile;
    string search, proteinStr, carbStr, fatStr, foodName;
    string toDelete;
    //int x = 0;

    inFile.open("food.txt");

    if (!inFile) {
        cout << "Our database is currently unreachable." << endl;
    } else {
        for (int x = 0; x < 15; x++)
            cout << "\n";
        cout << "Please enter a food you want to delete: \n" << endl;
        for (int x = 0; x < 15; x++)
            cout << "\n";
        cin >> toDelete;   // deleted = user inputted what they want deleted

        if (dailyLog.isEmptyList()) {   // case 1: list is empty
            cout << "Cannot delete from an empty list." << endl;
        } else {
            if (this->first->info == toDelete) { // Case 2
                current = this->first;
                this->first = this->first->link;
                this->count--;
                if (this->first == nullptr)  // the list has only one node
                    this->last = nullptr;
                delete current;
            } else { // search the list for the node with the given info
                found = false;
                trailCurrent = this->first;  // set trailCurrent to point to the first node
                current = this->first->link;  // set current to point to the second node
                while (current != nullptr && !found) {
                    if (current->info != toDelete) {
                        trailCurrent = current;
                        current = current->link;
                    } else
                        found = true;
                }

                if (found) {  // Case 3; if found, delete the node
                    trailCurrent->link = current->link;
                    this->count--;

                    if (this->last == current)  // node to be deleted was the last node
                        this->last = trailCurrent;  // update the value of last
                    delete current;  // delete the node from the list
                } else
                    cout << "The item to be deleted is not in "
                         << "the list." << endl;
            }  // end else
        }    // end else
        inFile.close();
    }*/

    //cout << "Would you like to delete another food?(Y/N) " << endl;
    //string deleteAnotherFood;
    //cin >> deleteAnotherFood;
//
    //if (deleteAnotherFood == "Y" || deleteAnotherFood == "y")
    //{
    //    deleteMeal();
    //}
//
    //else{
        calculateTotals();
    //}
}

float foodLog::getCalories(){
    return calories;
}
float foodLog::getProteins(){
    return proteins;
}
float foodLog::getCarbs(){
    return carbs;
}
float foodLog::getFats(){
    return fats;
}
foodLog::foodLog()
{
    calories=0.0;
    proteins=0.0;
    carbs=0.0;
    fats=0.0;
}

foodLog::~foodLog(){
}
