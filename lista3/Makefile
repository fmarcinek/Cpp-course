FLAGS = -std=c++11 -Wall -Wextra -O3 -flto
CCP = g++

main: Makefile main.o stack.o
	$(CCP) $(FLAGS) -o main main.o stack.o
main.o: Makefile main.cpp
	$(CCP) $(FLAGS) -c main.cpp -o main.o
stack.o: Makefile stack.cpp stack.h
	$(CCP) $(FLAGS) -c stack.cpp -o stack.o
