///////////////////////////////////////////////////////////////////////////////
//                   ALL STUDENTS COMPLETE THESE SECTIONS
// Main Class File:  P2.cpp
// File:             Student.cpp
// Semester:         CS368 Spring 2016
//
// Author:           Michael Simon
// CS Login:         msimon
// Lecturer's Name:  Deb Deppeler
//
//////////////////////////// 80 columns wide //////////////////////////////////

/**
 *
 * This class is for the type Student. There's a function to create the
 * student, construct a default student, deconstruct the student, 
 * get the student ID, get the GPA, and ge the credits.
 *
 * @author Michael Simon
 */
#include <vector>
#include <string>
#include "Student.h"
#include <stddef.h>
#include "iostream"
using namespace std;

/**
 * Constructs a default student with an ID of 0, 0 credits, and 0.0 GPA
 *
 */
Student::Student() {
    //currentStudent.Courses(numCourses);
    this->studentID = 0;
    this->credits = 0;
    this->GPA = 0;	    
}

/**
 * The Student Destructor destroys the entire student database
 *
 */
Student::~Student() {
	cout << "Student Destructor called for:: ID: " << studentID << endl;
}

/**
 * Initializes a student with a student ID, but sets 
 * credits to 0 and GPA to 0
 *
 * @param int ID - the ID for a student
 */
Student::Student(int ID) {
	this->studentID = ID;
	this->credits = 0;
	this->GPA = 0;
}

/**
 *
 * Creates a student with ID, credits and a grade point average
 *
 * @param int ID - a student ID
 * @param int cr - amount of credits for the students
 * @param double grPtAv - student's grade point average
 *
 */
Student::Student(int ID, int cr, double grPtAv) {
	this->studentID = ID;
	this->credits = cr;
	this->GPA = grPtAv;
}

/**
 *
 * Copy constructor
 *
 * @param const Student &S - address to a Student
 */
Student::Student (const Student &S): studentID(S.getID()), credits(S.getCredits()), GPA(S.getGPA()) {

}

/**
 * Assignment that sets the GPA, studentID, and credits
 *
 * @param const Student &S - address to a Student
 * @return returns the student after everything has been assigned
 */
Student & Student::operator=(const Student &S) {
	GPA = S.getGPA();
	studentID = S.getID();
	credits = S.getCredits();
	return *this;
}

/**
 *
 * Gets the GPA for a given student
 *
 * @return returns the student's GPA
 * 
 */
double Student::getGPA() const {
	return this->GPA;
}

/**
 *
 * Gets the ID for a given student
 *
 * @return returns the student's studentID
 */
int Student::getID() const {
	return this->studentID;
}

/**
 * 
 * Gets the credits for a given student
 *
 * @return returns the student's credits
 */
int Student::getCredits() const {
	return this->credits;
}

/**
 * Updates the total credits and overall GPA to take into account the 
 * additions of the given letter grade in a course with the given number
 * of credits. The update is done by first converting the letter grade 
 * into a numeric value. The new GPA is calculated. The total credits
 * is updated.
 *
 * @param char grade - the letter grade
 * @param int cr - credits for the course
 */ 
void Student::update(char grade, int cr) {
	int points;
	if (grade == 'A' || grade == 'a') {
		points = 4;
	} else if (grade == 'B' || grade == 'b') {
		points = 3;
	} else if (grade == 'C' || grade == 'c') {
                points = 2;
        } else if (grade == 'D' || grade == 'd') {
                points = 1;
        } else if (grade == 'F' || grade == 'f') {
                points = 0;
        }
	double totalPoints = (this->GPA * this->credits) + (points * cr);
	this->credits += cr;
	this->GPA = totalPoints / this->credits;
}

/**
 * Prints out the student to standard output
 */
void Student::print() const {
	if (this != NULL) {
		cout << this->studentID << "," << this->credits << "," << this->GPA;
	}
}


