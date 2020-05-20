#include <iostream>
#include <string>
#include <iomanip>
#include "networkStudent.h"
using namespace std;

//default constructor
NetworkStudent::NetworkStudent() :Student() {
	dType = NETWORKING;
};

//secondary
NetworkStudent::NetworkStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], degreeType degType)
	:Student(studentId, firstName, lastName, emailAddress, age, daysToComplete) {
	dType = NETWORKING;
};

//accessor
degreeType NetworkStudent::getDegreeProgram()
{
	return dType;
};

//print
void NetworkStudent::print()
{
	cout << left << setw(5) << "ID: " << GetStudentId() << "|";
	cout << setw(15) << "First Name: " << GetFirstName() << "|";
	cout << setw(15) << "Last Name: " << GetLastName() << "|";
	cout << setw(15) << "Email Address: " << GetEmailAddress() << "|";
	cout << setw(10) << "Age: " << GetAge() << "|";
	cout << setw(15) << "Days in course: " << GetAllDays() << "|";
	cout << setw(15) << "Degree Type: NETWORKING" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
};

//deconstructor
NetworkStudent::~NetworkStudent()
{
	Student::~Student();
};