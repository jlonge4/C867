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

    int lhs = rhs + 1;
    rhs = studentData.find(",",lhs);
    string ttl = studentData.substr(lhs,rhs - lhs);

}