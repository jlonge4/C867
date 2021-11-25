#include "roster.h" 
void Roster::parse(string studentData)
{
    DegreeProgram dP = SEURITY;
    if (studentData.at(0) == 'F') dP = NETWORK;
    else if (studentData.at(0) == 'N') dP = SOFTWARE;

    int rhs = studentData.find(",");
    string studID = studentData.substr(0, rhs);

    int lhs = rhs + 1;
    rhs = studentData.find(",",lhs);
    string ttl = studentData.substr(lhs,rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",",lhs);
    string ttl = studentData.substr(lhs,rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",",lhs);
    int p1 = stod(studentData.substr(lhs, rhs - lhss));

    lhs = rhs + 1;
    rhs = studentData.find(",",lhs);
    int p2 = stod(studentData.substr(lhs, rhs - lhss));

    lhs = rhs + 1;
    rhs = studentData.find(",",lhs);
    int p3 = stod(studentData.substr(lhs, rhs - lhss));

    add(studID, ttl, aut, p1, p2, p3, dP);

    void Roster::add(string studID, string firstName, string lastName, string email, 
    string age, int daysOne, int daysTwo, int daysThree)
    {
        double darr[3] = { daysOne,daysTwo,daysThree};

        studRostArr[++lastIndex] = new student(studID, firstName, lastName, email, age,
        darr, dP );
    }

    void Roster::printAll()
    {
        student::printHeader();
        for (int i=0; i <= Roster::lastIndex; i++)
        {
            cout << studRostArr[i]->getStudID(); cout << '\t';
            cout << studRostArr[i]->getFirstName(); cout << '\t';
            cout << studRostArr[i]->getLastName(); cout << '\t';
            cout << studRostArr[i]->getEmail(); cout << '\t';
            cout << studRostArr[i]->getAge(); cout << '\t';
            cout << studRostArr[i]->getDaysInCourse()[0]; cout << '\t';
            cout << studRostArr[i]->getDaysInCourse()[1]; cout << '\t';
            cout << studRostArr[i]->getDaysInCourse()[2]; cout << '\t';
            cout << degreeProgramStrings[studRostArr[i]->getDegreeProgram()] << std::endl; 
        }
    }

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::studRostArr[i]->getDegreeProgram() == dP) studRostArr[i]->print();
    }
    cout << std::endl;
}

void Roster::printInvalidSIDs()
{
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string studID = (studRostArr[i]->getStudID());
        if (studID.find('_') == string::npos ||
         (studId.find('X') == string::npos && studID.find('x') == string::npos))
         {
             any = true;
             cout << studID << ": " << studRostArr[i]->getFirstName() << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}

void Roster::printAverageDaysInCourse()
{
    for (int i = 0; i <= Roster::lastIndex; i++) {
        cout << studRostArr[i]->getStudID() << ": ";
        cout << (studRostArr[i]->getDaysInCourse()[0] + 
        studRostArr[i]->getDaysInCourse()[1] +
        studRostArr[i]->getDaysInCourse()[2])/3.0 << std::endl;
    }
    cout << std::endl;
}

void Roster::removeStudID(string studID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (studRostArr[i]->getStudID() == studID)
        {
            success = true;
            if (i < numStud - 1)
            {
                Student* temp = studRostArr[i];
                studRostArr[i] = studRostArr[numStud - 1];
                studRostArr[numStud - 1] = temp;
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
        delete studRostArr[i];
        studRostArr[i] = nullptr;
    } 
}
}