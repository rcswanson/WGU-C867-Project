//
//  main.cpp
//  C867 PA - JYM1 - Class Roster
//
//  Created by Rick Swanson on 1/14/22.
//

#include <iostream>
#include <string>
#include "roster.hpp"
using namespace std;

// Step 2, Req. F: Add an empty main() function. (Later filled in with steps 3, 4, 8, 9, and 10)

int main() {
    
    // Step 3, Req. A: Add studentData[] from task scenario.
    const string studentData[] =
    {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Rick,Swanson,rswan23@wgu.edu,26, 50, 57, 64,SOFTWARE"
    };
    
    // Step 4, Req. F1:  Print out the following info via the application.
    cout << "***************************************************" << endl;
    cout << "| Scripting and Programming - Applications - C867 |" << endl;
    cout << "|                 Language Used: C++              |" << endl;
    cout << "|               Student ID: #001543820            |" << endl;
    cout << "|                 Name: Rick Swanson              |" << endl;
    cout << "***************************************************" << endl;
    cout << endl;
    
    const int numStudents = 5;
    Roster roster;
    
    //Step 9, Req F3: Parse the string from studentData[]
    for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
    cout << "DISPLAYING ALL STUDENTS: " << endl;
    roster.printAll();
    cout << endl;
    
    // Step 10, Req. F4: Using the pseudocode, complete the main function.
    
    //Print Invalid Emails
    cout << "PRINTING INVALID EMAIL ADDRESSES: " << endl;
    roster.printInvalidEmails();
    cout << endl;
    
    // Print Average Days Left in Courses
    cout << "PRINTING AVERAGE DAYS PER CLASS: " << endl;
        for (int i = 0; i < numStudents; i++)
        {
        roster.printAverageDaysInCourse(roster.classRosterArray[i]->getID());
        }
    cout << endl;
    
    // Print By Software Degree Program
    cout << "PRINTING BY SOFTWARE DEGREE PROGRAM: " << endl;
    roster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    
    
    // Remove Student ID
    cout << "REMOVING STUDENT" << endl;
    roster.remove("A3");
    cout << endl;
    
    roster.remove("A3");
    cout << endl;
};


