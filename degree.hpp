//
//  degree.h
//  C867 PA - JYM1 - Class Roster
//
//  Created by Rick Swanson on 1/14/22.
//

#pragma once
#include <string>
using namespace std;

// Step 5, Req. C: In file degree.h define an enumerated data type DegreeProgram.

enum DegreeProgram {SECURITY, NETWORK, SOFTWARE};

//Parallel array of strings translates from enumerated data to strings
static const string degreeProgramString[] = {"SECURITY", "NETWORK", "SOFTWARE"};
