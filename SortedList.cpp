///////////////////////////////////////////////////////////////////////////////
//
// Main Class File: main.cpp
// File: Student.cpp
// Semester: CS368 Spring 2016
//
// Author: Michael Simon
// CS Login: msimon
// Lecturer's Name: Deppeler
// Lab Section:
//
///////////////////////////////////////////////////////////////////////////////

/**
 * The SortedList class uses an internal Listnode struct to store
 * information and pointer to the next node. It is used to implement
 * an ordeered singly-linked list of students. The list is ordered
 * by student ID from smallest to largest.
 *
 * @author Michael Simon
 */

#include "SortedList.h"
#include <iostream>
using namespace std;

/**
 * Constructs an empty list by setting head equal to NULL
 *
 */
SortedList::SortedList() {
	head = NULL;
}

/**
 * Destructor to free up the list of nodes
 * Checks if the head doesn't equal NULL and then
 * frees up the head
 *
 */
SortedList::~SortedList() {
	cout << "Destructor called for Sorted List" << endl;
	if (this->head != NULL) {
		freeList(this->head);
	}
}

/**
 * Copy Constructor. sets head equal to null and then copies 
 * the list that is passed in as the parameter
 *
 * @param const SortedList &S - address to the start of the passed
 * in sorted list
 *
 */
SortedList::SortedList(const SortedList &S) {
	head = NULL;
	head = copyList(S.head);
	cout << "Copy Constructor called for Sorted List" << endl;
}

/**
 * The copy assignment operation operator defines a protocol to use 
 * in the event that a copy assignment needs to be used (x = y)
 *
 * @param const SortedList &S - address to the start of the passed
 * in sorted list
 *
 * @return returns a pointer to the new list
 */
SortedList & SortedList::operator=(const SortedList &S) {
	cout << "Copy assignment operator called for sorted list." << endl;
	if (this != &S) {
		freeList(head);
		head = NULL;
		head = copyList(S.head);
	}
	return *this;
}

/**
 * CopyList copies all of the nodes from an old linked 
 * list to a new linked list.
 *
 * @param Listnode *L - pointer to a Listnode
 * @return headP - head of the new list
 *
 */
SortedList::Listnode *SortedList::copyList(Listnode *L) {
	Listnode *headP = new Listnode;
	Listnode *box = NULL;
	Listnode *currList = L;

	if (currList != NULL) {
		box = new Listnode;
		box->student = new Student(*(L->student));
		box->next = NULL;
		headP = box;
		while (currList->next != NULL) {
			currList = currList->next;
			box = box->next = new Listnode();
			box->student = new Student(*(currList->student));
			box->next = NULL;
		}
	}
	return headP;
}

/**
 * FreeList frees up the linked list nodes on the heap
 *
 * @param Listnode *L - pointer to the Listnode
 * 
 */
void SortedList::freeList (Listnode *L) {
	if (L == NULL) {
		Listnode *kill;
		while (L != NULL) {
			kill = L;
			L = L->next;
			delete kill;
		}
	}
}

/**
 * If a student with the same ID is not already in the list, inserts
 * the given student into the list in the appropriate place and returns
 * true. If there is already a student in the list with the same ID
 * then the list is not changed and false is returned.
 *
 * @param Student *s - pointer to the Student
 * @return returns true if a student isn't in the list already and is
 * inserted. Returns false if the student is already in the list and 
 * can't be inserted
 */ 
bool SortedList::insert(Student *s) {
	int counter = -1;
	if (head == NULL) {
		head = new Listnode;
		head->student = s;
		head->next = NULL;
		return true;
	}
	else {
		if (find(s->getID()) != NULL) {
			return false;
		}
		else {
			Listnode *box = new Listnode;
			box->student = s;
			Listnode *Parser = head;
			while (Parser->next != NULL && Parser->next->student->getID() < box->student->getID()) {
				counter++;
				Parser = Parser->next;
			}
			if (counter == -1 && Parser->student->getID() > box->student->getID()) {
				box->next = Parser;
				head = box;
			}
			else {
				if (Parser->next == NULL) {
					box->next = NULL;
				}
				else {
					box->next = Parser->next;
				}
				Parser->next = box;
			}
			return true;
		}
	}
}
 
/**
 * Searches the list for a student with the given student ID. If the
 * student is found, it is returned; if it is not found, NULL is returned.
 *
 * @param int studentID - a given student's student ID
 * @return returns the student if a student is found with that ID.
 * Returns NULL if student is not found
 */
Student *SortedList::find(int studentID) {
	Listnode *box = head;
	while (box != NULL) {
		if (box->student->getID() == studentID) {
			return box->student;
		}
		box = box->next;
	}
	return NULL;
}

/**Searches the list for a student with the given student ID. If the
 * student is found, the student is removed from the list and returned;
 * if no student is found with the given ID, NULL is returned. 
 * Note that the Student is NOT deleted - it is returned - however,
 * the removed list node should not be deleted.
 *
 * @param int studentID - a student's student ID
 * @return returns the student to be removed if that student is in 
 * the list, and returns NULL if that student can't be found
 *
 */
Student *SortedList::remove(int studentID) {
	Listnode *box = head;
	int counter = -1;
	Student *holder = NULL;
	while (box != NULL) {
		counter++;
		holder = box->student;
		if (holder->getID() == studentID) {
			if (counter == 0) {
				head = head->next;
				return holder;
			}
			else if (counter > 0) {
				box = head;
				for (int i = 0; i < counter - 1; i++) {
					box = box->next;
				}
				if (box->next->next == NULL) {
					box->next = NULL;
				}
				else {
					box->next = box->next->next;
				}
				return holder;
			}
		}
		box = box->next;
	}
	return NULL;
}

/**
 * Prints out the list of students to standard output. The students are 
 * printed in order of student ID (from smallest to largest), one per line
 * If the student list is empty, output "Empty student list.\n"
 *
 */ 
void SortedList::print() const {
	int ctr = 0;
	Listnode *box = new Listnode;
	box = head;
	while (box != NULL) {
		ctr++;
		if (box->student != NULL) {
			box->student->print();
		}
		cout << endl;
		box = box->next;
	}
	if (ctr == 0) {
		cout << "Empty student list." << endl;
	}
}






