#include <iostream>
#include <string>
#include "student.h"
#pragma once
using namespace std;

class NetworkStudent : public Student {
private:
	degreeType dType;
public:
	//Constructors
	NetworkStudent(); //default constructor
	NetworkStudent( //secondary
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
	~NetworkStudent();
};