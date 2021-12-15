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
    float getCalories();
    float getProteins();
    float getCarbs();
    float getFats();
    foodLog();
    ~foodLog();
};

void foodLog::calculateTotals(){
    linkedListIterator<string> listIt;

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
