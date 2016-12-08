///////////////////////////////////////////////////////////////////////////////
//			ALL STUDENTS COMPLETE THESE SECTIONS
// Title: P3
// Files: main.cpp Student.cpp Student.h SortedList.cpp SortedList.h
// Semester: CS368 Spring 2016
// 
// Author: Michael Simon
// Email: masimon2@wisc.edu
// CS Login: msimon
// Lecturer's Name: Deppeler
// Lab Section: 
//
///////////////////////////////////////////////////////////////////////////////

#include "SortedList.cpp"
#include "Student.cpp"
#include <iostream>
using namespace std;

/**
 * Main is just to test the Student.cpp and SortedList.cpp
 * files to check for memory leaks
 * <p>Bugs: None
 * 
 * @author Michael Simon
 */  

int main(int argc, char *argv[]) {

	SortedList *list = new SortedList();
	Student *s1 = new Student();
	Student *s2 = new Student(11111);
	Student *s3 = new Student(12345, 23, 3.0);
	Student *s4 = new Student(54321, 30, 2.5);
	s1->print();
	list->insert(s1);
	list->insert(s2);
	list->insert(s3);
	list->remove(11111);
	list->insert(s4);
	Student *s5 = new Student(*s2);
	list->insert(s5);
	list->print();
	list->~SortedList();
	delete list;
	return 0;
}












































