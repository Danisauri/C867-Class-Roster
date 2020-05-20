#include <iostream>
#include <string>
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#pragma once
using namespace std;

class Roster {
protected:
	int lastIndex; //number of entries
	int capacity; //maximum size of repository
	Student** classRosterArray; //dynamic array of pointers 
	degreeType dT;
public:
//constructors
	//default
	Roster();
	//secondary
	Roster(int capacity);

// Modifiers
	void parseThenAdd(string row);
	Student* getStudentIndex(int index);
	void add(string sid, string sfn, string sln, string sea, int sa, int d1, int d2, int d3, degreeType dT); //sets the instance variables from part D1 and updates the roster
	void remove(string sid); //removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
	
// Prints
	//prints a complete tab-separated list of student data using accessor functions with the provided format
	void printAll(); 
	//student’s average number of days in the three courses. The student is identified by the studentID parameter.
	void printAvgDaysInCourse(string sid); 
	//verifies student email addresses and displays all invalid email addresses to the use
	void printInvalidEmails(); 
	//prints out student information for a degree program specified by an enumerated type
	void printByDegreeType(degreeType degType);

// Deconstructor
	~Roster();

};

