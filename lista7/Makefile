Flags = -Wextra -Wall -std=c++11 -O3 -flto
CPP = g++

main : Makefile   map.o main.o
	$(CPP) $(Flags) -o main   map.o main.o

map.o : Makefile   map.cpp   map.h
	$(CPP) -c $(Flags) map.cpp -o  map.o

main.o : Makefile   main.cpp
	$(CPP) -c $(Flags) main.cpp -o main.o
