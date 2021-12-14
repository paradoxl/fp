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
    string name;
    int age;
    int height;
    int weight;
    string sex;

public:
    userProfile();
    ~userProfile();
    void printUser();
    void saveUser();
    void changeName();
    void removeMeal();
    void addMeal();
    bool exists();

    float proteinGoal;
    float carbGoal;
    float fatGoal;
    float calorieGoal;

    string foodName;
    string protein;
    string fat;
    string carb;

    vector<string> foodLog;
    vector<float> foodGoals;
};

void userProfile::changeName()
{
    string filename, currentName, Newname, newContent = "";
    string word, temp;
    int noOfWords = 0, noOfReplacements = 0, matched, replaced;

    cout << setw(80) << setfill('-') << "" << setfill(' ') << endl;
    cout << endl;
    //cout << "Enter a text file name: ";
    //cin >> filename;
    filename = "user.txt";
    cout << "Please type your current username: ";
    cin >> currentName;
    if(currentName == name){
        cout << "Please type your new username: ";
        cin >> Newname;
        cout << "\n";

        ifstream inFile;
        inFile.open(filename.c_str());

        if (!inFile) // If file cannot be opened
            cout << "Database unreachable. Try Again Later." << endl;

        else
        {

            string content((istreambuf_iterator<char>(inFile)), (istreambuf_iterator<char>()));
            inFile.close();

            for (int i = 0; content[i] != '\0'; i++)
            {
                if (content[i] == ' ' && i != 0)
                    noOfWords += 1;
                matched = 1;
                replaced = 0;

                if (content[i] == name[0])
                {
                    temp = "";

                    for (int j = 0; name[j] != '\0'; j++)
                    {
                        temp += content[i];
                        if (content[i] != name[j])
                        {
                            matched = 0;
                        }
                        i = i + 1;
                    }
                    i--;

                    if (matched == 1)
                    {
                        newContent += Newname;
                        noOfReplacements++;
                    }
                    else
                    {
                        newContent += temp;
                    }
                }
                else
                {
                    newContent += content[i];
                }
            }
            noOfWords += 1;
            ofstream outFile;
            outFile.open(filename.c_str());
            outFile << newContent << endl;
            outFile.close();
        }
    }
    else{
        cout << "Incorrect Username." << endl;
    }
    
}
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

    cout << "your calculated calorie goal based on this info is: " << calorieGoal << endl;

    ofstream write;

    write.open("user.txt", ios::app);

    if (!write.is_open())
    {
        cout << "cannot open file" << endl;
    }

    if (write.is_open())
    {
        write << name << " " << weight << " " << height << " " << age << " " << sex << endl;
        write << "Macros"
              << " " << calorieGoal << " " << proteinGoal << " " << carbGoal << " " << fatGoal << " " << calorieGoal << endl;

        // to seperate writes to deliniate users personal info with the macro goals
    }

    write.close();
}
bool userProfile::exists()
{

    ifstream inFile;

    inFile.open("user.txt");

    if (!inFile)
    {
        cout << "Cannot open input file." << endl;
    }
    string userName;

    cout << "\n\nPlease enter your username: " << endl;
    cin >> userName;
    
    if(userName == "Macros")
        return false;
    
    int curLine;
    string line;
    string temp;

    while (getline(inFile, line))
    {

        if (line.find(userName, 0) != string::npos)
        {
            return false;
        }
        else
        {
            return true;
        }
        // possible issue here on different compilers
    }

    // loading user goals

    inFile.close();
    return false;
}
void userProfile::addMeal()
{

    ifstream inFile;

    inFile.open("food.txt");

    if (!inFile)
    {
        cout << "Database can not be reached." << endl;
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

            foodLog.push_back(foodName);
            foodLog.push_back(protein);
            foodLog.push_back(carb);
            foodLog.push_back(fat);
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

                foodLog.push_back(protein);
                foodLog.push_back(carb);
                foodLog.push_back(fat);
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
void userProfile::printUser()
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
        }

        // possible issue here on different compilers
    }

    inFile.close();

    for (int i = 0; i < foodGoals.size(); i++)
    {
        cout << foodGoals.at(i);
        cout << "debug" << endl;
    }
    
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << setw(80) << setfill('-') << "" << setfill(' ') << endl;
    cout << "\t\t\tMacros " << endl;
    cout << setw(80) << setfill('-') << "" << setfill(' ') << endl;
    cout << "Caloric goal: " << calorieGoal << "Current Calories "
         << "todo" << endl;
    cout << "Protein goal: " << proteinGoal << "Current Protein: " << protein << endl;
    cout << "Carb goal: " << carbGoal << "Current carbs: " << carb << endl;
    cout << "fat goal: " << fatGoal << "CUrrent fat: " << fat << endl;
}
userProfile::userProfile()
{
}

userProfile::~userProfile()
{
}

/* code graveyard
while (getline(inFile, line))
            {
                if (line.find("M", 0) != string::npos)
                {
                    string testing;
                    inFile >> testing;
                    cout << "Here" << testing << endl;
                }
                return true;
            }

*/
