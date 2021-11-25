#include "roster.h" 
void roster::parse(string studentData)
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

    void roster::add(string studID, string firstName, string lastName, string email, 
    string age, int daysOne, int daysTwo, int daysThree)
    {
        double darr[3] = { daysOne,daysTwo,daysThree};

        studRostArr[++lastIndex] = new student(studID, )
    }


}