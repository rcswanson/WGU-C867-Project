//
//  student.hpp
//  C867 PA - JYM1 - Class Roster
//
//  Created by Rick Swanson on 1/14/22.
//

#pragma once
#include "degree.hpp"
#include <string>
using namespace std;

// Step 6, Req. D: 1. Create the Student class, which includes each of the following variables

class Student
{
  
public:
    const static int courseDayCompletion = 3;
private:
    string studentID;
    string fName;
    string lName;
    string email;
    int age;
    int days[courseDayCompletion];
    DegreeProgram degree;
public:
    // 2. Create the following Functions
    
    // 2a. Accessors
    string getID();
    string getFName();
    string getLName();
    string getEmail();
    int getAge();
    int* getDays();
    DegreeProgram getDegree();
    
    // 2b. Mutators
    void setID(string studentID);
    void setFName(string fName);
    void setLName(string lName);
    void setEmail(string email);
    void setAge(int age);
    void setDays(int courseDayCompletion[]);
    void setDegree(DegreeProgram degree);
    
    Student();
    Student(string studentID,
            string fName,
            string lName,
            string email,
            int age,
            int days[],
            DegreeProgram degree);
    ~Student(); // Destructor
    
    static void printHeader();
    //2e. Print specific student data
    void print();
    
};
