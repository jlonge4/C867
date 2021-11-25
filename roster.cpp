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
void Roster::printInvalidSIDs()
{
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string studID = (studRostArr[i]->getStudID());
        if (studID.find('_') == string::npos || (studId.find('X') == string::npos && studID.find('x') ==))
         {
             any = true;
             cout << studID << ": " << studRostArr[i]->getFirstName() << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}

void 
}