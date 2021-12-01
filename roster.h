#pragma once
#include "student.h"

class Roster 
{
private:
	int lastIndex = -1;
	const static int numStud = 5;
	Student* studRosterArr[numStud];

public:
	void parse(string row);
	void add(string sID,
		string slastName,
		string sfirstName,
		string semail,
		int sage,
		double sdaysInCourse1,
		double sdaysInCourse2,
		double sdaysInCourse3,
		DegreeProgram dP);
	void printAll();
	void printByDegreeProgram(DegreeProgram dP);
	void printInvalidSIDs();
	void printAverageDaysInCourse(std::string studID);
	void removeStudID(string studID);
	
	~Roster();
}


;