//
//  roster.hpp
//  C867 PA - JYM1 - Class Roster
//
//  Created by Rick Swanson on 1/14/22.
//

#pragma once
#include "student.hpp"

// Step 7, Req E: Create the roster class.
class Roster
{
public:
    int lastIndex = -1;
    const static int numStudents = 5;
    Student *classRosterArray[numStudents]; //Step 7, Req E: 1. Create an array of pointers to hold the data provided in the studentData table.
public:
    // Step 7, Req E3. Define the following functions (Roster.cpp)
    void parse(string row); // will separate the data in the studentData table by using a comma as a delimeter
    // the separated data from the parse will then be added into these fields to create 5 student objects.
    void add(string studentID,
             string firstName,
             string lastName,
             string emailAddress,
             int age,
             int daysInCourse1,
             int daysInCourse2,
             int daysInCourse3,
             DegreeProgram degree);
    void remove(string studentID); // If a student ID does not exist, information will print stating that said ID is non-existent.
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degree);
    ~Roster();
    
};
