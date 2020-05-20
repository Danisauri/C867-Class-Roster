#include <iostream>
#include <string>
#include "student.h"
#pragma once
using namespace std;

class SoftwareStudent : public Student {
private:
	degreeType dType;
public:
	//Constructors
	SoftwareStudent(); //default constructor
	SoftwareStudent( //secondary
		string studentId,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysToComplete[],
		degreeType dType
	);
	//Accesor
	degreeType getDegreeProgram();

	// Print
	void print();

	// Deconstructor
	~SoftwareStudent();
};