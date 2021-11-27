#include "roster.h" 
void Roster::parse(string studentData)
{
    DegreeProgram dP = NETWORK;
    if (studentData.at(1) == '3' || studentData.at(1) == '5') dP = SOFTWARE;
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
    double ageN = stod(studentData.substr(lhs, rhs - lhs));
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
    int days1,
    int days2,
    int days3,
    DegreeProgram dP)
{
    double daysInArr[3] = { days1,days2,days3 };

    studRosterArr[++lastIndex] = new Student(studID, firstName, lastName, email, age, daysInArr, dP);
    }

void Roster::printAll()
{
    Student::printHeader();
        for (int i=0; i <= Roster::lastIndex; i++)
        {
            cout << studRosterArr[i]->getStudID(); cout << '\t';
            cout << studRosterArr[i]->getFirstName(); cout << '\t';
            cout << studRosterArr[i]->getLastName(); cout << '\t';
            cout << studRosterArr[i]->getEmail(); cout << '\t';
            cout << studRosterArr[i]->getAge(); cout << '\t';
            cout << studRosterArr[i]->getDaysInCourse()[0]; cout << '\t';
            cout << studRosterArr[i]->getDaysInCourse()[1]; cout << '\t';
            cout << studRosterArr[i]->getDaysInCourse()[2]; cout << '\t';
            cout << degreeProgramStrings[studRosterArr[i]->getDegreeProgram()] << std::endl; 
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
        string studID = (studRosterArr[i]->getStudID());
        if (studID.find('_') == string::npos ||
         (studID.find('X') == string::npos && studID.find('x') == string::npos))
         {
             any = true;
             cout << studID << ": " << studRosterArr[i]->getFirstName() << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}

void Roster::printAverageDaysInCourse()
{
    for (int i = 0; i <= Roster::lastIndex; i++) {
        cout << studRosterArr[i]->getStudID() << ": ";
        cout << (studRosterArr[i]->getDaysInCourse()[0] + 
        studRosterArr[i]->getDaysInCourse()[1] +
        studRosterArr[i]->getDaysInCourse()[2])/3.0 << std::endl;
    }
    cout << std::endl;
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
