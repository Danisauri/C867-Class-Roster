#include <string>
#include <iostream>
#include "student.h"
using namespace std;

//Default Constructor
Student::Student() {
	this->studentId = "noID";
	this->firstName = "noFirstName";
	this->lastName = "noLastName";
	this->emailAddress = "noEmailAddress";
	this->age = 0;
	for (int i = 0; i < daysArraySize; i++)
		this->daysToComplete[i] = 0;
}

// Second Constructor
Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToComplete[]) {
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysArraySize; i++)
		this->daysToComplete [i] = daysToComplete [i];
}

//Accessors
string Student::GetStudentId() {
	return studentId;
};
string	Student::GetFirstName() {
	return firstName;
};
string Student::GetLastName() {
	return lastName;
};
string Student::GetEmailAddress() {
	return emailAddress;
};
int Student::GetAge() {
	return age;
};
int* Student::GetDaysToComplete() {
	return daysToComplete;
};
string Student::GetAllDays() {
	string d = "";
	d.append("{ ");
	for (int i = 0; i < daysArraySize; i++) {
		d.append(to_string(daysToComplete[i]));
		d.append(", ");
	};
	d.replace((d.size() - 2), 2, " }");
	return d;
}


//Mutators
void Student::SetStudentId(string studentId) {
	this->studentId = studentId;
};
void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
};
void Student::SetLastName(string lastName) {
	this->lastName = lastName;
};
void Student::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
};
void Student::SetAge(int age) {
	this->age = age;
};
void Student::SetDaysToComplete(int daysToComplete[]) {
	for (int i = 0; i < daysArraySize; i++)
		this->daysToComplete[i] = daysToComplete[i];
}

//destructor
Student::~Student() {
	//does not do anything since it has no dynamic information
};
