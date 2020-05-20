#include <iostream>
#include "roster.h"

//Constructors
Roster::Roster() {
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
	this->dT = SOFTWARE; //default value assigned by me
};
Roster::Roster(int capacity) {
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];
	this->dT = SOFTWARE;
};

Student* Roster::getStudentIndex(int index) {
	return classRosterArray[index];
}

void Roster::parseThenAdd(string row) {
	if (lastIndex < capacity) {
		lastIndex ++;
		if (row[0] != 'A') {
			cerr << "Invalid Student ID (PROGRAM EXIT)" << endl;
			exit(-1);
		}
		//Get ID
		int rhs = row.find(",");
		string sid = row.substr(0, rhs);

		//Get FirstName
		int lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string sfn = row.substr(lhs, rhs - lhs);

		//Get LastName
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string sln = row.substr(lhs, rhs - lhs);

		//Get EmailAddress
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string sea = row.substr(lhs, rhs - lhs);

		//Get Age
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int sa = stoi(row.substr(lhs, rhs - lhs));

		//Get DaysToComplete
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int d1 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int d2 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int d3 = stoi(row.substr(lhs, rhs - lhs));

		//Get Degree
		lhs = rhs + 1;
		string subrow = (row.substr(lhs, (row.length() - rhs + 1)));
		if (subrow == "SECURITY") {
			dT = SECURITY;
		};
		if (subrow == "NETWORKING") {
			dT = NETWORKING;
		};
		if (subrow == "SOFTWARE") {
			dT = SOFTWARE;
		};

		//use Add Method
		add(sid, sfn, sln, sea, sa, d1 , d2, d3, dT);
	}
	else {
		cout << "Error!";
		exit(-1);
	}
}

void Roster::add(string sid, string sfn, string sln, string sea, int sa, int d1, int d2, int d3, degreeType dT) {
	int daysToComplete[Student::daysArraySize];
	daysToComplete[0] = d1;
	daysToComplete[1] = d2;
	daysToComplete[2] = d3;
	if (dT == SECURITY) {
		this->classRosterArray[lastIndex] = new SecurityStudent(sid, sfn, sln, sea, sa, daysToComplete, dT);
	}
	else if (dT == SOFTWARE) {
		this->classRosterArray[lastIndex] = new SoftwareStudent(sid, sfn, sln, sea, sa, daysToComplete, dT);
	}
	else if (dT == NETWORKING) {
		this->classRosterArray[lastIndex] = new NetworkStudent(sid, sfn, sln, sea, sa, daysToComplete, dT);
	}
	else {
		cout << "ERROR!" << endl;
	}
}

void Roster::printAll() {
	for (int i = 0; i <= this->lastIndex; i++)
		(this->classRosterArray)[i]->print(); //run-time polymorphism
}

void Roster::remove(string sid) {
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->GetStudentId() == sid) {
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
			return; 
		}
	}
	cout << "Student " << sid <<" Not Found!" << endl;
}

void Roster::printAvgDaysInCourse(string sid) {
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->GetStudentId() == sid) {
			found = true;
			int* pint = classRosterArray[i]-> GetDaysToComplete();
			double p = static_cast<double> ((pint[0] + pint[1] + pint[2]) / 3);
			cout << "Average amount of days to complete a course: " << p << endl;
		}
	}
	if (!found) {
		cout << "Student not found!" << endl;
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i <= lastIndex; ++i) {
		string email = classRosterArray[i]->GetEmailAddress();
		if ((email.find("@") == -1) || (email.find(" ") != string::npos) || (email.find(".") == string::npos)) {
			cout << "The email for student: " << classRosterArray[i]->GetFirstName() << " " << classRosterArray[i]->GetLastName() << " is not valid: " << email << endl;
		}
	}
}

void Roster::printByDegreeType(degreeType degType) {
	cout << endl;
	cout << "Print Student by Degree: " << degreeString[degType] << endl;
	for (int i = 0; i <= lastIndex; ++i) {
		if (this->classRosterArray[i]->getDegreeProgram() == degType) {
			this->classRosterArray[i]->print();
		}
	}
	}
Roster::~Roster() {
	for (int i = 0; i < lastIndex; i++) {
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
};



int main() {
	const int numStudents = 5;
	const string studentData[numStudents] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORKING",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Daniela,Vidal,dvidal6@wgu.edu,30,10,20,30,SOFTWARE"
	};

//Make Repository
	Roster * rep = new Roster(numStudents);
	cout << "Gathering data..." << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < numStudents; i++) {
		rep->parseThenAdd(studentData[i]);
	}

//Print All
	rep->printAll();

// Print invalid emails
	cout << endl;
	cout << "Verifing validity of Emails..." << endl;
	rep->printInvalidEmails();

//Print avg days
	cout << endl;
	cout << "Printing average days of student in a class: " << endl;
	for (int i = 0; i < numStudents; i++) {
		cout << "Student ID: " << rep->getStudentIndex(i)->GetStudentId() << " - ";
		rep->printAvgDaysInCourse(rep->getStudentIndex(i)->GetStudentId());
	}

//Print by type
	rep->printByDegreeType(SOFTWARE);

//Remove A3
	cout << endl;
	cout << "Removing A3" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	rep->remove("A3");
	rep->remove("A3");
return 0;
}