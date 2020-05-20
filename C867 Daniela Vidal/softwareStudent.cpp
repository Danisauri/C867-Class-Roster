#include <iostream>
#include <string>
#include <iomanip>
#include "softwareStudent.h"
using namespace std;

//default constructor
SoftwareStudent::SoftwareStudent() :Student() {
	dType = SOFTWARE;
};

//secondary
SoftwareStudent::SoftwareStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], degreeType degType)
	:Student(studentId, firstName, lastName, emailAddress, age, daysToComplete) {
	dType = SOFTWARE;
};

//accessor
degreeType SoftwareStudent::getDegreeProgram()
{
	return dType;
};

//print
void SoftwareStudent::print()
{
	cout << left << setw(5) << "ID: " << GetStudentId() << "|";
	cout << setw(15) << "First Name: " << GetFirstName() << "|";
	cout << setw(15) << "Last Name: " << GetLastName() << "|";
	cout << setw(15) << "Email Address: " << GetEmailAddress() << "|";
	cout << setw(10) << "Age: " << GetAge() << "|";
	cout << setw(15) << "Days in course: " << GetAllDays() << "|";
	cout << setw(15) << "Degree Type: SOFTWARE" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
};

//deconstructor
SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
};