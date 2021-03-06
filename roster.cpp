#include <iostream>
#include <string>
#include "roster.h" 
void Roster::parse(string studentData)
{
    DegreeProgram dP = NETWORK;
    if (studentData.at(1) == '3' || (studentData.at(1) == '5')) dP = SOFTWARE;
    else if (studentData.at(1) == '1' || studentData.at(1) == '4') dP = SECURITY;
    

    int rhs = studentData.find(",");
    string studID = studentData.substr(0, rhs);

    int lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstN = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastN = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emailN = studentData.substr(lhs, rhs - lhs);

    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int ageN = stoi(studentData.substr(lhs, rhs - lhs)); 
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    double p1 = stod(studentData.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    double p2 = stod(studentData.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    double p3 = stod(studentData.substr(lhs, rhs - lhs));

    add(studID, firstN, lastN, emailN, ageN, p1, p2, p3, dP);
}
void Roster::add(string studID,
    string firstName,
    string lastName,
    string email,
    int age,
    double days1,
    double days2,
    double days3,
    DegreeProgram dP)
{
    double daysInArr[3] = { days1,days2,days3 };
    studRosterArr[++lastIndex] = new Student(studID, firstName, lastName, email, age, daysInArr, dP);
    }

void Roster::printAll()
{
    Student::printHeader();
    {
        
        //cout << "This class conatins these students:" << endl;
        for (int i = 0; i <= Roster::lastIndex; i++) {
            if (studRosterArr[i] == nullptr) {
            }
            else {
                studRosterArr[i]->print();
            }
        }
    }
    }

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::studRosterArr[i]->getDegreeProgram() == degreeProgram) studRosterArr[i]->print();
    }
    cout << std::endl;
}

void Roster::printInvalidSIDs()
{
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string studId = (studRosterArr[i]->getStudID());
        string email = (studRosterArr[i]->getEmail());
        if (email.find('.') == string::npos ||
         (email.find('@') == string::npos && email.find(' ') == string::npos))
         {
             any = false;
             cout << studId << ": " << studRosterArr[i]->getEmail() << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}

/*void Roster::printAverageDaysInCourse()
{
    for (int i = 0; i <= Roster::lastIndex; i++) {
        cout << studRosterArr[i]->getStudID() << ": ";
        cout << (studRosterArr[i]->getDaysInCourse()[0] + 
        studRosterArr[i]->getDaysInCourse()[1] +
        studRosterArr[i]->getDaysInCourse()[2])/3.0 << std::endl;
    }
    cout << std::endl;
}*/
void Roster::printAverageDaysInCourse(std::string studID) {
    int average;
    int daysA;
    int daysB;
    int daysC;
    int indexNum = 0;

    
    for (int i = 0; i <= Roster::lastIndex; i++) {
        studRosterArr[i]->getStudID() = studID;
        indexNum = i;

        daysA = studRosterArr[indexNum]->getDaysInCourse()[0];
        daysB = studRosterArr[indexNum]->getDaysInCourse()[1];
        daysC = studRosterArr[indexNum]->getDaysInCourse()[2];

        average = ((daysA + daysB + daysC) / 3);

        std::cout << "Average of days in course for student " << studRosterArr[i]->getStudID() << ": " << average;
        std::cout << std::endl;

    }

   
  
}


void Roster::removeStudID(string studID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (studRosterArr[i]->getStudID() == studID)
        {
            success = true;
            if (i < numStud - 1)
            {
                Student* temp = studRosterArr[i];
                studRosterArr[i] = studRosterArr[numStud - 1];
                studRosterArr[numStud - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (success)
    {
        cout << studID << " removed from roster." << std::endl << std::endl;
        this->printAll();
    }
    else cout << studID << " not found." << std::endl << std::endl;
} 

Roster::~Roster()
{
    cout << "Destructor Called!" << std::endl << std::endl;
    for (int i = 0; i < numStud; i++)
    {
        cout << "Destroying student ID" << i + 1 << std::endl;
        delete studRosterArr[i];
        studRosterArr[i] = nullptr;
    } 
}
