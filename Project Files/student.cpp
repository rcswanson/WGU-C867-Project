//
//  student.cpp
//  C867 PA - JYM1 - Class Roster
//
//  Created by Rick Swanson on 1/14/22.
//

#include "student.hpp"
#include <iostream>
#include <string>
using namespace std;

Student::Student()
{
    this->studentID = "";
    this->fName = "";
    this->lName = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < courseDayCompletion; i++) this->days[i] = 0;
    this->degree = DegreeProgram::SECURITY;
};

Student::Student(string studentID, string fName, string lName, string email, int age, int days[], DegreeProgram degree)
{
    this->studentID = studentID;
    this->fName = fName;
    this->lName = lName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < courseDayCompletion ; i++) this->days[i] = days[i];
    this->degree = degree;
};

Student::~Student() {}

string Student::getID() { return this->studentID; }
string Student::getFName() { return this->fName; }
string Student::getLName() { return this->lName; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
int* Student::getDays() { return this->days; }
DegreeProgram Student::getDegree() { return this->degree; };
    
    
void Student::setID(string studentID) { this->studentID = studentID; }
void Student::setFName(string fName) { this->fName = fName; }
void Student::setLName(string lName) { this->lName = lName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDays(int days[])
{
    for (int i = 0; i < courseDayCompletion ; i++) this->days[i] = days[i];
};
void Student::setDegree(DegreeProgram degree) { this->degree = degree; }

void Student::printHeader()
{
    cout << "ID | First Name | Last Name | Email Address | Age | Days Until Completion | Degree" << endl;
}

// Prints the students data of the determined ID.
void Student::print()
{    
    cout << this->getID() << '\t';
    cout << this->getFName() << '\t';
    cout << this->getLName() << '\t';
    cout << this->getEmail() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getDays()[0] << '\t';
    cout << this->getDays()[2] << '\t';
    cout << this->getDays()[3] << '\t';
    cout << degreeProgramString[this->getDegree()] << '\n';
}
