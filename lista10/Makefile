
Flags = -Wextra -Wall -std=c++11
CPP = g++


main : Makefile   main.o 
	$(CPP) $(Flags) -o main   main.o 

main.o : Makefile   main.cpp   units.h 
	$(CPP) -c $(Flags) main.cpp -o  main.o



