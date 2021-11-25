#pragma once
#include <iostream>	
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;


class Student
{
public:
	const static int daysArrSize = 3;

private:
	string studID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysInCourse[daysArrSize];
	DegreeProgram degreeProgram;

public:
	Student();
	Student(string studID, string firstName, string lastName, string email,
		int age, int daysInCourse[], DegreeProgram degreeProgram);
	~Student();

	//getters
	string getStudID;
	string getFirstName;
	string getLastName;
	string getEmail;
	int getAge;
	int* getDaysInCourse[daysArrSize];
	DegreeProgram getDegreeProgram; 

	//setters
	void setStudID(string studID);
	void setFirstName(string firstName);
	void setLastName(string  lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysInCourse(int daysInCOurse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	static void printHeader();

	void print();
};

