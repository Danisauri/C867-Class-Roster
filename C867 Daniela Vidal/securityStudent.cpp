#include <iostream>
#include <string>
#include <iomanip>
#include "securityStudent.h"
using namespace std;

//default constructor
SecurityStudent::SecurityStudent():Student() {
	dType = SECURITY;
};

//secondary
SecurityStudent::SecurityStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], degreeType degType)
	:Student(studentId, firstName, lastName, emailAddress, age, daysToComplete) {
	dType = SECURITY;
};

//accessor
degreeType SecurityStudent::getDegreeProgram()
{
	return dType;
};

//print
void SecurityStudent::print()
{
	cout << left << setw(5) << "ID: " << GetStudentId() << "|";
	cout << setw(15) << "First Name: " << GetFirstName() << "|";
	cout << setw(15) << "Last Name: " << GetLastName() << "|";
	cout << setw(15) << "Email Address: " << GetEmailAddress() << "|";
	cout << setw(10) << "Age: " << GetAge() << "|";
	cout << setw(15) << "Days in course: " << GetAllDays() << "|";
	cout << setw(15) << "Degree Type: SECURITY" << endl;;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
};

//deconstructor
SecurityStudent::~SecurityStudent()
{
	Student::~Student();
};