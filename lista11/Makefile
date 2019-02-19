Flags = -Wall -Wextra -std=c++11

main:	Makefile	main.o rectangle.o triangle.o circle.o
	g++ $(Flags) -o main main.o rectangle.o triangle.o circle.o
main.o:	Makefile 	main.cpp rectangle.h triangle.h circle.h surface.h
	g++ -c $(Flags) main.cpp -o main.o


rectangle.o: Makefile 	rectangle.cpp rectangle.h surf.h
	g++ -c $(Flags) rectangle.cpp -o rectangle.o
triangle.o: Makefile 	triangle.cpp triangle.h surf.h
	g++ -c $(Flags) triangle.cpp -o triangle.o
circle.o: Makefile 	circle.cpp circle.h surf.h
	g++ -c $(Flags) circle.cpp -o circle.o

clean:
	rm *.o main
