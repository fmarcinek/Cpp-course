Flags = -std=c++11 -Wall -Wextra -O3 -flto

main : main.o string.o
	g++ -o main main.o string.o $(Flags)

string.o : string.cpp string.h
	g++ -o string.o -c string.cpp $(Flags)

main.o : main.cpp string.h
	g++ -o main.o -c main.cpp $(Flags)
