#include "student.h"

student::Student() {
	this -> studID = "";
	this -> firstName = "";
	this -> lastName = "";
	this -> email = "";
	this-> age = 0;
	for (int i = 0; i < daysArrSize; i++) this->daysInCourse[i] = 0;
	this -> degreeProgram = DegreeProgram::NETWORK;
}

student::Student(string studID, string firstName, string lastName, string email, int age,
	int daysInCourse[], DegreeProgram degreeProgram)
{
	this->studID = studID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < daysArrSize; i++) this->daysInCourse[i] = 0;
	this->degreeProgram = degreeProgram;
}

student::~Student() {}

string student::getStudID() { return this->studID;  }
string student::getFirstName() { return this->firstName;  }
string student::getLastName() { return this->lastName; }
string student::getEmail() { return this->email; }
int student::getAge() { return this->age; }
int* student::getDaysInCourse() { return this->daysInCourse; }
DegreeProgram student::getDegreeProgram() { return this->degreeProgram; }

void student::setStudID(string studID) { this->studID = studID; }
void student::setFirstName(string firstName) { this->firstName = firstName; }
void student::setLastName(string lastName) { this->lastName = lastName; }
void student::setEmail(string email) { this->email = email; }
void student::setAge(int age) { this->age = age; }
void student::setDaysInCourse(int daysInCourse[]) { for (int i = 0; i < daysArrSize; i++) this->daysInCourse[i] = 0; }
void student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

void student::printHeader() {
	cout << "Output Format: Student ID | First Name | Last Name | Email | Age | Days In Course | Degree Program\n";
}

void student::print() {
	cout << this->getStudID() << '\t/';
	cout << this->getFirstName() << '\t/';
	cout << this->getLastName() << '\t/';
	cout << this->getEmail() << '\t/';
	cout << this->getAge() << '\t/';
	cout << this->getDaysInCourse()[0] << ',';
	cout << this->getDaysInCourse()[1] << ',';
	cout << this->getDaysInCourse()[2] << ',';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
	
}



