#pragma once
#include "student.h"

class Roster {
private:
	int lastIndex = -1;
	const static int numStud = 5;
	Student* studentRosterArr[numStud];

public:

	void parse(string row);

	void add(string sID,
		string slastName,
		string sfirstName,
		string semail,
		int sage,
		int sdaysInCourse1,
		int sdaysInCourse2,
		int sdaysInCourse3,
		DegreeProgram dP);
	
	void printAll();
	void printByDegreeProgram(DegreeProgram dP);
	void printInvalidSIDs();
	void printAverageDaysInCourse();
	void removeStudID(string studID);
	~Roster();
};


