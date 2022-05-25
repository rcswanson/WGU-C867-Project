//
//  roster.cpp
//  C867 PA - JYM1 - Class Roster
//
//  Created by Rick Swanson on 1/14/22.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "roster.hpp"
using namespace std;


// Step 7, Req E: 2. Parses the Student Data table using the comma.
void Roster::parse(string studentdata)
{
   
    long int rightSide = studentdata.find(",");
    string ID = studentdata.substr(0, rightSide);
    
    long int leftSide = rightSide + 1;
    rightSide = studentdata.find(',', leftSide);
    string fName = studentdata.substr(leftSide, rightSide - leftSide);
    
    leftSide = rightSide + 1;
    rightSide = studentdata.find(',', leftSide);
    string lName = studentdata.substr(leftSide, rightSide - leftSide);
    
    leftSide = rightSide + 1;
    rightSide = studentdata.find(',', leftSide);
    string email = studentdata.substr(leftSide, rightSide - leftSide);
    
    leftSide = rightSide + 1;
    rightSide = studentdata.find(',', leftSide);
    int age = stoi(studentdata.substr(leftSide, rightSide - leftSide));
    
    leftSide = rightSide + 1;
    rightSide = studentdata.find(',', leftSide);
    int day1 = stoi(studentdata.substr(leftSide, rightSide - leftSide));
    
    leftSide = rightSide + 1;
    rightSide = studentdata.find(',', leftSide);
    int day2 = stoi(studentdata.substr(leftSide, rightSide - leftSide));
    
    leftSide = rightSide + 1;
    rightSide = studentdata.find(',', leftSide);
    int day3 = stoi(studentdata.substr(leftSide, rightSide - leftSide));
    
    leftSide = rightSide + 1;
    rightSide = studentdata.find(',', leftSide);
    
    DegreeProgram degree = SECURITY;
    
    if (studentdata.at(leftSide) == 'S' && studentdata.at(leftSide + 1) == 'E') degree = SECURITY;
    else if (studentdata.at(leftSide) == 'S' && studentdata.at(leftSide + 1) == 'O') degree = SOFTWARE;
    else if (studentdata.at(leftSide) == 'N') degree = NETWORK;
    
    add(ID, fName, lName, email, age, day1, day2, day3, degree);
};

// Step 7, Req E: 3. Define the following functions.

// Adds all the parsed information to the Student Object --------------------
void Roster::add(string studentID, string fName, string lName, string email, int age, int day1, int day2, int day3, DegreeProgram degree)
{
    int dayArray[3] = {day1, day2, day3};
    classRosterArray[++lastIndex] = new Student(studentID, fName, lName, email, age, dayArray, degree);
};

// Remove by Student ID -------------------------
void Roster::remove(string studentID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID() == studentID)
        {
            success = true;
            if (i <numStudents - 1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (success)
    {
        cout << "Student " << studentID << " removed from roster." << endl << endl;
        this->printAll();
    }
    else cout << studentID << " not found." << endl << endl;
};

// Prints the Student Data table correctly formatted ---------------------
void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();

};

void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++) {
        {
            if (classRosterArray[i]->getID()==studentID)
            {
        cout << studentID << ": ";
        cout << (classRosterArray[i]->getDays()[0]
        + classRosterArray[i]->getDays()[1]
        + classRosterArray[i]->getDays()[2])/3 << endl;
            }
        }
    }
};

void Roster::printInvalidEmails()
{
        bool any = false;
        for (int i = 0; i <= Roster::lastIndex; i++)
        {
            string email = (classRosterArray[i]->getEmail());
            if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos))
            {
                any = true;
                cout << email << ":" << classRosterArray[i]->getFName() << endl;
            }
        }
        if (!any) cout << "NONE" << endl;
        //prints if no invalid emails
};

void Roster::printByDegreeProgram(DegreeProgram degree)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (Roster::classRosterArray[i]->getDegree() == degree) classRosterArray[i]->print();
        cout << endl;
    }
}

// Step 11, Req. F5: Release allocated memory.
Roster::~Roster()
{
    cout << "Destructor called!" << std::endl << std::endl; // Prints when memory is released
    for (int i=0; i < numStudents; i++)
    {
        cout << "Removing student #" << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

