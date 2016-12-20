# cs368_p3

Description
In programming assignment 2 the issues of proper memory management were ignored. The compiler defaults for the destructors, 
copy constructors, and copy assignment operators were assumed to be good enough. For this assignment you'll write your own to ensure that
memory dynamically allocated in the classes is correctly managed. You'll also write a main function that demonstrates the usefulness of 
the added functions.

Step 1. Use valgrind to demonstrate the memory leaks
Write a main function, in the file main.cpp that tests your Student and SortedList classes. This function should fully exercise the 
destructors, copy constructors, and copy assignment operators of each class.

Next, create an executable named runMain: using the current (incomplete) class implementations for Student and SortedList and 
your main.cpp file. Run valgrind on the executable and save valgrind results to pretest.txt.  It should report storage leaks. 
Save this results file.  

To run valgrind and save results, use this command:

    valgrind runMain > pretest.txt
Step 2. Finish implementing Student class
Add these to your Student.h and Student.cpp (can uncomment in the Student.h file)

a destructor,
a copy constructor, and
a copy assignment operator (operator= that defines the assignment operator for two Student objects)
Make sure to modify both Student.h and Student.cpp. 

Step 3. Finish implementing SortedList class
Finish implementing the SortedList classes and be sure to implement the following: (can uncomment in the SortedList.h file)

a destructor
a copy constructor
a copy assignment operator (operator= that defines the assignment operator for two SortedList objects)
Make sure to modify both SortedList.h and SortedList.cpp as necessary and include the following (further described below).

private:
    static void      freeList (ListNode *L);
    static ListNode *copyList (ListNode *L);
Step 3a. Implement the auxiliary freeList Function for the SortedList Class
Both the destructor and copy assignment operator of the SortedList class must deallocate the nodes of a linked list returning them 
to the free storage (i.e., the heap). Therefore, it is a good idea to write an auxillary function to handle this task.

Implement an auxilliary function, named freeList, having one parameter, a pointer to a ListNode. This function traverses the linked list, returning each node to free storage (i.e., heap). It is used by both the destructor and copy assignment operator.

Step 3b. Implement the auxiliary copyList Function for the SortedList Class
Both the copy constructor and copy assignment operator make a deep copy of an existing linked list. Therefore, it is a good idea to 
write an auxiliary function to handle this task.

Implement an auxilliary function, named copyList, having one parameter, a pointer to a ListNode. This function returns a pointer to the 
first node of a copy of original linked list. It is used by both the copy constructor and the copy assignment operator.

Note both auxilliary functions are implemented as static functions of the SortedList class and should be used as such. They are also 
private intended to only be used within the SortedList class. Also note in SortedList.cpp the the modifier "static" is not included.

Step 4. Demonstrate the Difference
Rebuild and rerun your executable named runMain: using your updated classes and your main.cpp file. Run valgrind on the new executable 
and save the results in postTest.txt.  There should be no storage leaks. If there are fix your implementations until there are no 
storage leaks.

Compare the differences between the Student class and the SortedList class. Determine for which class(es) the updates mattered. 
Include your conclusions in the header comments of the main.cpp file.
