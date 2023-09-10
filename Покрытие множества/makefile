all: main.o src.o
	g++ main.o src.o -o myexe.exe

main.o: main.cpp
	g++ -c main.cpp -o main.o

src.o: src.cpp head.h
	g++ -c src.cpp -o src.o

clean:
	rm *.o
