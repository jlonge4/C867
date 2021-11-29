#include "student.h"
#include <iostream>

Student::Student() {
	this -> studID = "";
	this -> firstName = "";
	this -> lastName = "";
	this -> email = "";
	this-> age = 0;
	for (int i = 0; i < daysArrSize; i++) { this->daysInCourse[i] = daysInCourse[i]; }
	this -> degreeProgram = DegreeProgram::NETWORK;
}

Student::Student(string studID, string firstName, string lastName, string email, int age,
	double daysInCourse[3], DegreeProgram degreeProgram)
{
	this->studID = studID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < daysArrSize; i++) { this->daysInCourse[i] = daysInCourse[i]; } 
	this->degreeProgram = degreeProgram;
}

Student::~Student() {}

string Student::getStudID() { return this->studID;  }
string Student::getFirstName() { return this->firstName;  }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
double* Student::getDaysInCourse() { return this->daysInCourse; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setStudID(string studID) { this->studID = studID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(double daysInCourse[]) { for (int i = 0; i < daysArrSize; i++) this->daysInCourse[i] = 0; }
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

void Student::printHeader() {
	cout << "Output Format: Student ID | First Name | Last Name | Email | Age | Days In Course | Degree Program\n";
}

void Student::print() {
	cout << this->getStudID(); cout << '\t';
	cout << this->getFirstName(); cout << '\t';
	cout << this->getLastName(); cout << '\t';
	cout << this->getEmail(); cout << '\t';
	cout << this->getAge(); cout << '\t';
	cout << this->getDaysInCourse()[0]; cout << ',';
	cout << this->getDaysInCourse()[1]; cout << ',';
	cout << this->getDaysInCourse()[2]; cout << ',';
	cout << degreeProgramStrings[this->getDegreeProgram()]; cout << '\n';
	
}



