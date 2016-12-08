main: main.cpp Student.h Student.cpp SortedList.cpp SortedList.h
	g++ -g main.cpp Student.h SortedList.h
main.cpp: Student.h Student.cpp SortedList.h SortedList.cpp
	g++ -c -g main.cpp
Student.cpp: Student.h SortedList.cpp SortedList.h
	g++ -c -g Student.cpp
SortedList.cpp: Student.h SortedList.h
	g++ -c -g SortedList.cpp
clean:
	\rm *.o *.h.gch
