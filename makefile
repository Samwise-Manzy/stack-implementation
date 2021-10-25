#makefile
a.out: stackTest.o myStack.o
		g++ stackTest.o myStack.o
myStack.o: stackTest.cpp myStack.h
		g++ -c -std=gnu++0x stackTest.cpp
myStack.o: myStack.cpp myStack.h
		g++ -c -std=gnu++0x myStack.cpp