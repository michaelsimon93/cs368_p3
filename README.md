# cs368_p3

Description
In programming assignment 2 the issues of proper memory management were ignored. The compiler defaults for the destructors, 
copy constructors, and copy assignment operators were assumed to be good enough. For this assignment you'll write your own to ensure that
memory dynamically allocated in the classes is correctly managed. You'll also write a main function that demonstrates the usefulness of 
the added functions.

Step 1. Use valgrind to demonstrate the memory leaks
Wrote a main function, in the file main.cpp that tests your Student and SortedList classes

Created an executable named runMain: using the current (incomplete) class implementations for Student and SortedList and 
your main.cpp file. Run valgrind on the executable and save valgrind results to pretest.txt.  It should report storage leaks. 
Save this results file.  

To run valgrind and save results, use this command:

    valgrind runMain > pretest.txt
Step 2. Implemented Student class
Added these to my Student.h and Student.cpp:

a destructor,
a copy constructor, and
a copy assignment operator (operator= that defines the assignment operator for two Student objects)

Step 3. Implemented SortedList class
Finished implementing the SortedList classes and be sure to implement the following: 

a destructor
a copy constructor
a copy assignment operator (operator= that defines the assignment operator for two SortedList objects)


Step 3a. Implemented the auxiliary freeList Function for the SortedList Class
Both the destructor and copy assignment operator of the SortedList class deallocate the nodes of a linked list returning them 
to the free storage (i.e., the heap).

Implemented an auxilliary function, named freeList, having one parameter, a pointer to a ListNode. This function traverses the linked list, returning each node to free storage (i.e., heap). 

Step 3b. Implemented the auxiliary copyList Function for the SortedList Class
Both the copy constructor and copy assignment operator make a deep copy of an existing linked list. 

Implemented an auxilliary function, named copyList, having one parameter, a pointer to a ListNode. This function returns a pointer to the 
first node of a copy of original linked list. It is used by both the copy constructor and the copy assignment operator.

Step 4.
Rebuilt and reran my executable named runMain: using my updated classes and my main.cpp file. Ran valgrind on the new executable 
and saved the results in postTest.txt.  There should be no storage leaks. 

