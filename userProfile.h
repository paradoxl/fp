#include <iostream>
#include <fstream>
#include <ostream>
#include <iomanip>
#include <string>

#include "foodLog.h"

using namespace std;

class userProfile
{
private:
    string name;
    int age;
    int height;
    int weight;
    string sex;

    foodLog foodHistory;
    float proteinGoal;
    float carbGoal;
    float fatGoal;
    float calorieGoal;
public:
    userProfile();
    ~userProfile();
    void printUser();
    void addMeal();
    void saveUser();
    void changeName();
    void removeMeal();
    bool exists();
};

//displays caloric goals and current foods
void userProfile::printUser(){
    ifstream inFile;
    string line;

    inFile.open("user.txt");

    if (!inFile){
        cout << "Cannot open input file." << endl;
        return;
    }

    while (getline(inFile, line)){
        inFile >> line;
        if (line == name){
            while(getline(inFile, line)){
                cout << line;
                inFile >> line;
                if(line == "Macros"){
                    inFile >> calorieGoal;
                    inFile >> proteinGoal;
                    inFile >> carbGoal;
                    inFile >> fatGoal; 
                    break;  
                }
            }
        break;
        }
    }
    
    inFile.close();

    float caloriesRemaining = calorieGoal - foodHistory.getCalories();
    float proteinRemaining = proteinGoal - foodHistory.getProteins();
    float carbsRemaining = carbGoal - foodHistory.getCarbs();
    float fatRemaining = fatGoal - foodHistory.getFats();

    for(int x = 0; x < 20; x++)
        cout << endl;
    cout << setw(90) << setfill('-') << "" << setfill(' ') << endl;
    cout << "\t\t\t\t\tMacros: " << endl;
    cout << setw(90) << setfill('-') << "" << setfill(' ') << endl;
    cout << "Caloric goal: \t" << calorieGoal << "\t\tCurrent Calories: " << right << foodHistory.getCalories() << "\t\tCalories Remaining: " << right << caloriesRemaining <<endl;
    cout << "Protein goal: \t" << proteinGoal << "\t\tCurrent Protein:  " << right << foodHistory.getProteins() << "\t\tProtein Remaining:  " << right << proteinRemaining <<endl;
    cout << "Carb goal: \t" << carbGoal << "\t\tCurrent carbs:    " << right << foodHistory.getCarbs() <<  "\t\tCarbs Remaining:    " << right << carbsRemaining << endl;
    cout << "fat goal: \t" << fatGoal << "\t\tCurrent fat:      " << right << foodHistory.getFats() <<  "\t\tFat Remaining:      " << right << fatRemaining << endl;
}

void userProfile::addMeal(){
    foodHistory.addMeal();
}

//gives the user the ability to edit their name
void userProfile::changeName(){
    string filename, currentName, Newname, newContent = "";
    string word, temp;
    int noOfWords = 0, noOfReplacements = 0, matched, replaced;

    cout << setw(80) << setfill('-') << "" << setfill(' ') << endl;
    cout << endl;
    //cout << "Enter a text file name: ";
    //cin >> filename;
    filename = "user.txt";
    for(int x = 0; x < 15; x++)
        cout << "\n";
    cout << "Please type your current username: " << endl;
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

//saves an initial user to the db
void userProfile::saveUser()
{
    for(int x = 0; x < 15; x++)
        cout << "\n";
    cout << setw(80) << setfill('-') << "" << setfill(' ') << endl;
    cout << endl
         << setw(25) << ""
         << "Welcome to the account creation screen: " << endl
         << endl;
    cout << "Please enter your desired username: ";
    cin >> name;
    cout << "Please enter your weight: ";
    cin >> weight;
    cout << "Please enter your height: ";
    cin >> height;
    cout << "Please enter your age: ";
    cin >> age;
    cout << "Please enter your gender: ";
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
        write.eof();
        write << name << " " << weight << " " << height << " " << age << " " << sex << endl;
        write <<"Macros" <<" " <<calorieGoal << " " << proteinGoal << " " << carbGoal << " " << fatGoal << " " << calorieGoal << endl;

        // to seperate writes to deliniate users personal info with the macro goals
    }

    write.close();
}

//checks to see if use is in db
bool userProfile::exists()
{

    ifstream inFile;

    inFile.open("user.txt");

    if (!inFile)
    {
        cout << "Cannot open input file." << endl;
    }
    string userName;

    for(int x = 0; x < 15; x++)
        cout << "\n";
    cout << "Please enter your username: ";
    for(int x = 0; x < 15; x++)
        cout << "\n";
    cin >> userName;
    if(userName == "Macros" || userName <= "10")
        return false;

    string line;
    size_t found;

    while (getline(inFile, line)){
        inFile >> line;
        found = line.find(userName);
        if (found != string::npos){
            name = userName;
            return true;
        }
    }

    inFile.close();
    return false;
}





userProfile::userProfile()
{
}

userProfile::~userProfile()
{
}
