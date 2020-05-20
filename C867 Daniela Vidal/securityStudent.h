#include <iostream>
#include <string>
#include "student.h"
#pragma once
using namespace std;

class SecurityStudent : public Student {
private:
	degreeType dType;
public:
//Constructors
	SecurityStudent(); //default constructor
	SecurityStudent( //secondary
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
	~SecurityStudent(); 
};