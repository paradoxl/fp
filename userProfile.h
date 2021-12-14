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
    void saveUser();
    void changeName();
    void removeMeal();
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

    
    vector<float> foodGoals;
};

//displays switch case based menu for navigation


//gives the user the ability to edit their name
void userProfile::changeName()
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

    if (!inFile) // If file cannot be opened
        cout << "File cannot be opened." << endl;

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

//saves an initial user to the db
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
        write <<"Macros" <<" " <<calorieGoal << " " << proteinGoal << " " << carbGoal << " " << fatGoal << " " << calorieGoal << endl;

        // to seperate writes to deliniate users personal info with the macro goals
    }

    write.close();
}

//checks to see if use is in db
bool userProfile::exsists()
{

    ifstream inFile;

    inFile.open("user.txt");

    if (!inFile)
    {
        cout << "Cannot open input file." << endl;
    }
    string userName;

    cout << "What is the name that is attached to the account?" << endl;
    cin >> userName;
    // this block runs twice for some reason
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





userProfile::userProfile()
{
}

userProfile::~userProfile()
{
}
