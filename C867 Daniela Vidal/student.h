#include <iostream>
#include <string>
#include "degree.h"
#pragma once
using namespace std;

class Student {

public:
	const static int daysArraySize = 3; //size of the array of days to finish courses

protected:
//variables
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComplete [daysArraySize];

public:
//Constructors
	Student(); //default
	Student( //second
		string studentId,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysToComplete[]);

//Accessor
	string GetStudentId();
	string	GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int* GetDaysToComplete();
	virtual degreeType getDegreeProgram () = 0; // virtual
	string GetAllDays();

//Mutators
	void SetStudentId(string sstudentId);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmailAddress(string emailAddress);
	void SetAge(int age);
	void SetDaysToComplete(int daysToComplete[]);



//print, also virtual because as degreeType is virtual, this print is incomplete
	virtual void print() = 0;


//destructor
	~Student();

};

