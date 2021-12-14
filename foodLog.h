#include <iostream>
#include <vector>
#include <fstream>
#include <ostream>
#include <string>
using namespace std;

class foodLog
{
private:
    
public:
    void addMeal();
    void printUser();
    foodLog();
    ~foodLog();

    string foodName;
    string protein;
    string fat;
    string carb;
    vector<string> food;

    float calorieGoal;
    float proteinGoal;
    float carbGoal;
    float fatGoal;

    float proteinConversion;
    float carbConversion;
    float fatConversion;
    float totalCalories;

    vector <float> foodGoal;
};

//displays caloric goals and current foods
void foodLog::printUser()
{

    ifstream inFile;

    inFile.open("user.txt");
    string line;

    if (!inFile)
    {
        cout << "Cannot open input file." << endl;
        return;
    }

    while (getline(inFile, line))
    {
        string sent;

        inFile >> line;

        if (line == "Macros")
        {
            inFile >> calorieGoal;
            inFile >> proteinGoal;
            inFile >> carbGoal;
            inFile >> fatGoal;

                totalCalories = (proteinConversion * 9) + (carbConversion * 4) + (fatConversion * 4);
        }

        // possible issue here on different compilers
    }

    inFile.close();

    for (int i = 0; i < food.size(); i++)
    {
        cout << food.at(i);
        
    }

    float caloriesRemaining = calorieGoal - totalCalories;
    float proteinRemaining = proteinGoal - proteinConversion;
    float carbsRemaining = carbGoal - carbConversion;
    float fatRemaining = fatGoal - fatConversion;


    cout << "Macros: " << endl;
    cout << "Caloric goal: \t" << calorieGoal << "\tCurrent Calories: "<< totalCalories << "\tCalories Remaining: \t" << caloriesRemaining <<endl;
    cout << "Protein goal: \t" << proteinGoal << "\tCurrent Protein: " << proteinConversion << "\tProtein Remaining: \t" << proteinRemaining <<endl;
    cout << "Carb goal: \t" << carbGoal << "\tCurrent carbs: \t" << carbConversion <<  "\tCarbs Remaining: \t" << carbsRemaining << endl;
    cout << "fat goal: \t" << fatGoal << "\tCurrent fat: \t" << fatConversion <<  "\tFat Remaining: \t" << fatRemaining << endl;
}

//adds food to program
void foodLog::addMeal()
{

    ifstream inFile;

    inFile.open("food.txt");

    if (!inFile)
    {
        cout << "Cannot open input file." << endl;
        return;
    }
    string search;

    cout << "Which food would you like to search" << endl;
    cin >> search;

    int curLine;
    string line;
    string temp;
    bool searchFinished;

    while (getline(inFile, line))
    {

        if (line.find(search, 0) != string::npos)
        {
            cout << "found: " << search << " Macronutrients " << line << endl;
            // searchFinished = true;
        }
    }

    while (getline(inFile, line))
    {

        inFile >> temp;
        if (temp == search)
        {
            foodName = temp;
            inFile >> protein;
            inFile >> carb;
            inFile >> fat;

            food.push_back(foodName);
            food.push_back(protein);
            food.push_back(carb);
            food.push_back(fat);

             proteinConversion = std::stof(protein);
             carbConversion = std::stof(carb);
             fatConversion = std:: stof(fat);
            
        }

        //
    }

    inFile.close();

    cout << "If we are displaying multiple results please refine your search below" << endl;
    cout << "Please press Y to refine search" << endl;
    cout << "Please Press N to confirm selection" << endl;
    string refine;
    cin >> refine;

    if (refine == "y" || refine == "Y")
    {
        ifstream inFile;
        string search2;
        inFile.open("food.txt");
        cin >> search2;
        while (getline(inFile, line))
        {
            inFile >> temp;
            if (temp == search2)
            {
                foodName = temp;
                inFile >> protein;
                inFile >> carb;
                inFile >> fat;

                food.push_back(protein);
                food.push_back(carb);
                food.push_back(fat);

             proteinConversion = std::stof(protein);
             carbConversion = std::stof(carb);
             fatConversion = std:: stof(fat);
            }

            curLine++;
            if (line.find(search2, 0) != string::npos)
            {
                cout << "found: " << search2 << " Macronutrients " << line << endl;
            }
        }

        inFile.close();
    }

    else if (refine == "n" || refine == "N")
    {
        cout << "Thanks for adding that food!" << endl;
    }
    else
    {
        cout << "incorrect input" << endl;
    }

    cout << "Would you like to add another food to this meal? " << endl;
    string additionalFood;
    cin >> additionalFood;

    if (additionalFood == "Y" || additionalFood == "y")
    {
        addMeal();
    }

    else if (additionalFood == "N" || additionalFood == "n")
    {
        cout << "thanks! your values are:" << endl;

        printUser();
    }
}

foodLog::foodLog()
{
}

foodLog::~foodLog()
{
}
