#include <iostream>
#include <fstream>
#include <ostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class userProfile
{
private:
public:
    userProfile();
    ~userProfile();
    void printUser();
    void saveUser();
    void changeName();
    void removeMeal();
    void addMeal();
    bool exsists();

    string name;
    int age;
    int height;
    int weight;
    string sex;

    float proteinGoal;
    float carbGoal;
    float fatGoal;
    float calorieGoal;

    string foodName;
    string protein;
    string fat;
    string carb;
   
   vector<string> foodLog;
};

void userProfile::saveUser()
{
    cout << setw(80) << setfill('-') << "" << setfill(' ') << endl;
    cout << endl
         << setw(25) << ""
         << "Hello, tell us about yourself" << endl
         << endl;
    cout << "Please enter your first name: ";
    cin >> name;
    cout << "Please enter your weight: ";
    cin >> weight;
    cout << "Please enter your height: ";
    cin >> height;
    cout << "Please enter your age: ";
    cin >> age;
    cout << "Please enter your sex: ";
    cin >> sex;
    cout << "\n";

    cout << setw(80) << setfill('-') << "" << setfill(' ') << endl;
    cout << endl
         << setw(25) << ""
         << "Lets get to know your goals!" << endl
         << endl;
    cout << "What is your protien goal: ";
    cin >> proteinGoal;
    cout << "What is your carb goal: ";
    cin >> carbGoal;
    cout << "What is your fat goal: ";
    cin >> fatGoal;
    cout << "\n";

    calorieGoal = (proteinGoal * 9) + (carbGoal * 4) + (fatGoal * 4);

    cout << "Your calculated calorie goal based on this info is: " << calorieGoal << endl;

    ofstream write;

    write.open("user.txt", ios::app);

    if (!write.is_open())
    {
        cout << "cannot open file" << endl;
    }

    if (write.is_open())
    {
        write << name << " " << weight << " " << height << " " << age << " " << sex << " " << proteinGoal << " " << carbGoal << " " << fatGoal << " " << calorieGoal << endl;
    }

    write.close();
}


bool userProfile::exsists()
{
    ifstream inFile;

    inFile.open("user.txt");

    if (!inFile)
    {
        cout << "Cannot open input file." << endl;
    }

    cout << setw(80) << setfill('-') << "" << setfill(' ') << endl;
    cout << endl;
    cout << "What is the name that is attached to the account?" << endl;  // this block runs twice for some reason
    cin >> name;
    
    int curLine;
    string line;
    string temp;
    string first;
    string last;
    int isFirst = 0;
    int count = 0;
    
    while (getline(inFile, line))
    {
        if(isFirst == 0)
        {
            first = line;
            isFirst = 1;
            last = line; //in each iteration last will be updated
            count++;
            return true;
         
        }
        else
        {
            cout << "could not read name from file" << endl;
            return false;
        }
    }
    return 0;
}



void userProfile::addMeal()
{
    
    ifstream inFile;

    vector<string> foodLog;

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
        }
        foodLog.push_back(foodName);
        foodLog.push_back(protein);
        foodLog.push_back(carb);
        foodLog.push_back(fat);
        
       
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
            }
            curLine++;
            if (line.find(search2, 0) != string::npos)
            {
                cout << "found: " << search2 << " Macronutrients " << line << endl;
            }
        }
        // foodLog.push_back(foodName);
        // foodLog.push_back(protein);
        // foodLog.push_back(carb);
        // foodLog.push_back(fat);

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

    cout << "Would you like to add another food to this meal? " <<endl;
    string additionalFood;
    cin>>additionalFood;

    if (additionalFood == "Y" || additionalFood == "y"){
        addMeal();
    }

    else if( additionalFood == "N" || additionalFood == "N"){
        cout << "thanks! your values are:" <<endl;

        printUser();
    }
}


void userProfile::printUser()
{
    for (int i = 0; i < foodLog.size(); i++){
        protein = foodLog.at(2);
        carb = foodLog.at(3);
        fat = foodLog.at(4);
        //assumes there is only one food added
        //doesnt actually add;
        cout << foodLog.at(i);
    }
    cout << setw(80) << setfill('-') << "" << setfill(' ') << endl;
    cout << endl;
    cout << "Macros: " << endl;
    cout << "Caloric goal: " << calorieGoal << "         Current Calories: " << "todo" <<endl;
    cout << "Protein goal: " << proteinGoal << "         Current Protein: " << protein << endl;
    cout << "Carb goal: " << carbGoal << "            Current Carbs: " << carb << endl;
    cout << "Fat goal: " << fatGoal << "             Current Fat: " << fat << endl;
}


userProfile::userProfile()
{
}



userProfile::~userProfile()
{
}
